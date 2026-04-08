project(IsEngineCore)

add_library(Engine STATIC)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_sources(Engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Stub.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/SDL/SdlPlatform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/SDL/SdlWindow.cpp
)

target_link_libraries(Engine PRIVATE 
    SDL3::SDL3
)

if(WIN32)
    target_compile_definitions(Engine PRIVATE SDL_MAIN_HANDLED)
endif()

if(MSVC)
    target_compile_options(Engine PRIVATE /W4 /WX)
else()
    target_compile_options(Engine PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_include_directories(Engine PRIVATE
    Include
)
