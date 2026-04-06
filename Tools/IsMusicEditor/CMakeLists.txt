project(IsMusicEditor)

find_package(SDL3 CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
    Main.cpp
)

target_link_libraries(Engine PRIVATE SDL3::SDL3)
