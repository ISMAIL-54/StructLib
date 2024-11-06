cmake_minimum_required(VERSION 3.27)

project(StructLib VERSION 1.0)

include_directories(include)

add_library(SL_STACK STATIC include/sl_stack.hpp)

set_target_properties(SL_STACK PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE SL_STACK)


