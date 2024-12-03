cmake_minimum_required(VERSION 3.5)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(geometry)

# Locate all .cpp files in the generated subdirectory
file(GLOB GENERATED_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/generated/*.cpp")

# Add an executable target
add_library(geometry SHARED
    "Factory.cpp"
    ${GENERATED_SOURCES}
)

target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/generated)


# Add glm
find_package(glm REQUIRED)

# Link against the libraries
target_link_libraries(geometry common ${GLM_LIBRARIES})