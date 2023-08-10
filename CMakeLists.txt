cmake_minimum_required(VERSION 3.25)
project(Shopping_list)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

set(SOURCE_FILE Item.cpp Item.h List.cpp List.h ScratchPad.cpp ScratchPad.h)
add_executable(Shopping_list main.cpp)
add_library(core ${SOURCE_FILE})
target_link_libraries(Shopping_list core)