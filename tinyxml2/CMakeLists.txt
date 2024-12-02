# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

add_library (tinyxml2 SHARED 
	"tinyxml2.cpp"
)

target_include_directories(tinyxml2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
