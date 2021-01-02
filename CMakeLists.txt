cmake_minimum_required(VERSION 3.17)
project(matrix)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp)
add_executable(matrix ${SOURCE_FILES})

include_directories(src)
add_subdirectory(src)

target_link_libraries(matrix src)

add_subdirectory(Google_tests)