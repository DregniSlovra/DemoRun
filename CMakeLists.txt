cmake_minimum_required(VERSION 3.14)

project(DemoRun VERSION 0.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

add_executable(DemoRun sources/main.cpp
                        sources/Board.cpp
                        sources/Tile.cpp
                        sources/Pawn.cpp)

target_include_directories(DemoRun PUBLIC includes)
