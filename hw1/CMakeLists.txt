cmake_minimum_required(VERSION 3.20)

project(hw1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hw1_tests
    tests/tests.cpp
)

add_executable(hw1_bench
    bench/bench.cpp
)

target_include_directories(hw1_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(hw1_bench PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})