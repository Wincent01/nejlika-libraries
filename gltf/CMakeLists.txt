cmake_minimum_required(VERSION 3.10)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(gltf)

# Add an executable target
add_library(gltf SHARED
    "Converter.cpp"
    "TerrainConverter.cpp"
    "ConverterHelper.cpp"
    "gltf.cpp"
)
target_include_directories(gltf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add glm
find_package(glm REQUIRED)

# Link against the libraries
target_link_libraries(gltf geometry world ${GLM_LIBRARIES})