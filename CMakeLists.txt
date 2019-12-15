cmake_minimum_required(VERSION 3.10)

# project name
project(OpenCV_Test VERSION 1.0)

# set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set( SOURCES
  main.cpp
  lib/utility.cpp)

# add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# specify verion headers
configure_file(config.h.in config.h)
# add version header to builf directory
target_include_directories(OpenCV_Test PUBLIC "${PROJECT_BINARY_DIR}")
