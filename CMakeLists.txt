# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

project(cli)

# Set C language standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

file(
	GLOB SOURCES_LIBBCRYPT
	LIST_DIRECTORIES false
	RELATIVE "${PROJECT_SOURCE_DIR}"
	${PROJECT_SOURCE_DIR}/libbcrypt/src/*.c
)

add_library(bcrypt SHARED ${SOURCES_LIBBCRYPT})

target_include_directories(bcrypt PUBLIC ${CMAKE_SOURCE_DIR}/libbcrypt/include/bcrypt)

add_subdirectory(common)
add_subdirectory(core)
add_subdirectory(gltf)
add_subdirectory(sqlite3)
add_subdirectory(tinyxml2)
add_subdirectory(cli)
add_subdirectory(geometry)
add_subdirectory(world)

