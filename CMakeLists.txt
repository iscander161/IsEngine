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

set(PLATFORM_DEFS "${COMPILE_DEFINITIONS} ")

if(WIN32)
    add_definitions(-DPLATFORM_WINDOWS)
elseif(APPLE)
    add_definitions(-DPLATFORM_MACOS)
elseif(UNIX)
    add_definitions(-DPLATFORM_LINUX)
endif()

add_definitions()

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
