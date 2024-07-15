# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(cpp_template)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# get the libs
find_package(fmt CONFIG REQUIRED)
find_package(doctest CONFIG REQUIRED)

# lib target
add_subdirectory(src)

# tests target
add_subdirectory(test)
