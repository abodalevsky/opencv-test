cmake_minimum_required(VERSION 3.10)

# project name
project(OpenCV_Test VERSION 1.0)

# set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_PREFIX_PATH "/Users/abodalevsky/Projects/opencv/build")

find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

set( SOURCES
  main.cpp
  lib/utility.cpp)

# add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# specify verion headers
configure_file(config.h.in config.h)
# add version header to builf directory
target_include_directories(OpenCV_Test PUBLIC "${PROJECT_BINARY_DIR}")

# Link your application with OpenCV libraries
target_link_libraries(OpenCV_Test PRIVATE ${OpenCV_LIBS})
