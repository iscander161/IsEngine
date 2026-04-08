cmake_policy(VERSION 3.20)

cmake_minimum_required(VERSION 3.20)

if(${CMAKE_VERSION} VERSION_GREATER "3.20") 
    set(CMAKE_CXX_STANDARD 23)
else()
    set(CMAKE_CXX_STANDARD 20)
endif()

set(PRODUCT_NAME_EN "IsEngine Project Software")
set(PRODUCT_NAME_RU "Системное программное обеспечение IsEngine")
set(PRODUCT_VERSION_MAJOR 0)
set(PRODUCT_VERSION_MINOR 0)
set(PRODUCT_VERSION_PATCH 1)

project(IsEngine VERSION ${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}.${PRODUCT_VERSION_PATCH})

execute_process(COMMAND
  git describe --match=NeVeRmAtCh --always --abbrev=40
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  OUTPUT_VARIABLE PRODUCT_COMMIT
  ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
string(TOUPPER "${PRODUCT_COMMIT}" PRODUCT_COMMIT)

execute_process(COMMAND
    git log -1 --format=%ad --date=local
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE PRODUCT_COMMIT_DATE
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_definitions(
    -DUNICODE
    -D_UNICODE
    -DPRODUCT_VERSION_MAJOR=${PRODUCT_VERSION_MAJOR}
    -DPRODUCT_VERSION_MINOR=${PRODUCT_VERSION_MINOR}
    -DPRODUCT_VERSION_PATCH=${PRODUCT_VERSION_PATCH}
    -DPRODUCT_COMMIT=${PRODUCT_COMMIT}
    -DPRODUCT_COMMIT_DATE=${PRODUCT_COMMIT_DATE}
)

include(ProcessorCount)
ProcessorCount(NUM_CORES)

if(NUM_CORES GREATER 0)
    # Используем половину доступных ядер (минимум 1)
    math(EXPR MAX_PARALLEL "${NUM_CORES} / 2")
    
    # Убеждаемся, что хотя бы 1 процесс используется
    if(MAX_PARALLEL LESS 1)
        set(MAX_PARALLEL 1)
    endif()
    
    message(STATUS "System has ${NUM_CORES} CPU cores")
    message(STATUS "Limiting parallel jobs to ${MAX_PARALLEL} (half of system cores)")
    
    # Для CMake 3.12+ используем JOB_POOLS
    if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.12")
        set_property(GLOBAL PROPERTY JOB_POOLS compile_pool=${MAX_PARALLEL})
        set(CMAKE_JOB_POOL_COMPILE compile_pool)
        
        # Опционально: ограничиваем и линковку (обычно легче)
        # set(CMAKE_JOB_POOL_LINK compile_pool)
    endif()
    
    # Устанавливаем переменную окружения для cmake --build
    set(ENV{CMAKE_BUILD_PARALLEL_LEVEL} ${MAX_PARALLEL})
else()
    # Если не удалось определить, используем значение по умолчанию
    message(WARNING "Could not detect number of CPU cores, defaulting to 2 parallel jobs")
    set(ENV{CMAKE_BUILD_PARALLEL_LEVEL} 2)
endif()

set(PLATFORM_DEFS "${COMPILE_DEFINITIONS} ")

if(WIN32)
    add_definitions(-DPLATFORM_WINDOWS)
elseif(APPLE)
    add_definitions(-DPLATFORM_MACOS)
elseif(UNIX)
    add_definitions(-DPLATFORM_LINUX)
endif()

# ============================================================================
# Vulkan SDK - Полная сборка из подмодулей
# ============================================================================

# Добавляем Vulkan-Headers (только заголовки, не требует сборки)
add_subdirectory(Libs/VulkanSDK/Vulkan-Headers)

# Настройка Vulkan-Loader
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_LOADER ON CACHE BOOL "" FORCE)
set(BUILD_WERROR OFF CACHE BOOL "" FORCE)
set(UPDATE_DEPS ON CACHE BOOL "" FORCE)  # Автоматически загружает и собирает зависимости

# Добавляем Vulkan-Loader (он сам подтянет glslang, SPIRV-Tools и др. через UPDATE_DEPS)
add_subdirectory(Libs/VulkanSDK/Vulkan-Loader)

# Настройка Validation Layers
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_WERROR OFF CACHE BOOL "" FORCE)
set(UPDATE_DEPS ON CACHE BOOL "" FORCE)
add_subdirectory(Libs/VulkanSDK/Vulkan-ValidationLayers)

# Создаём цель Vulkan::Vulkan для линковки с движком
if(NOT TARGET Vulkan::Vulkan)
    add_library(Vulkan::Vulkan UNKNOWN IMPORTED)
    set_target_properties(Vulkan::Vulkan PROPERTIES
        IMPORTED_LOCATION ${Vulkan_LIBRARY}
        INTERFACE_INCLUDE_DIRECTORIES ${Vulkan_INCLUDE_DIRS}
    )
endif()

set(SDL3_LIBUSB OFF CACHE BOOL "" FORCE)
set(SDL3_HIDAPI_LIBUSB OFF CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "Build SDL3 as shared library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build SDL3 as static library" FORCE)

if(MINGW)
    add_compile_options($<$<COMPILE_LANGUAGE:C>:-Wno-incompatible-pointer-types>)
endif()

# Подключаем SDL как подмодуль
add_subdirectory(Libs/SDL)

# Подключаем движок и игру
add_subdirectory(Engine)

# Тесты
add_subdirectory(Tests/SdlTest01)
