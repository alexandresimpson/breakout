cmake_minimum_required(VERSION 3.21)
project(breakout)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib
        GIT_TAG 4.0.0
)
FetchContent_MakeAvailable(raylib)

add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
        )

add_executable(breakout main.cpp paddle.cpp ball.cpp window.h game.h game.cpp asset_loader.cpp play_area.cpp block.cpp)
target_link_libraries(breakout raylib)
add_dependencies(${PROJECT_NAME} copy_assets)
