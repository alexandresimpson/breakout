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

add_executable(breakout main.cpp paddle.cpp ball.cpp ball.h window.h game.h game.cpp)
target_link_libraries(breakout raylib)
