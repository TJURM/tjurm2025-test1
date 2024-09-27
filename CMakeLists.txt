cmake_minimum_required(VERSION 3.5)
project(tjurm-test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -O3 -g")

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR})
file(GLOB_RECURSE sources "src/*.cpp")

add_executable(tjurm-test main.cpp ${sources})