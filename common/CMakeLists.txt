# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(common)

# Add an executable target
add_library(common SHARED
    "Reader.cpp"
    "Writer.cpp"
)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
