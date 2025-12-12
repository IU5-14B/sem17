cmake_minimum_required(VERSION 3.10)
project(seminar17 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(seminar17
    src/main.cpp
    src/heap.cpp
)

target_include_directories(seminar17 PRIVATE include)
