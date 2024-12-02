# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})

# Add an executable target
add_executable(cli
    "main.cpp"
)

# Link to the core library
target_link_libraries(cli PRIVATE core)