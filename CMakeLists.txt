cmake_minimum_required(VERSION 3.27)

project(StructLib VERSION 1.0)

include_directories(include)

add_library(SL_STACK STATIC include/sl_stack.h)

add_library(SL_VECTOR STATIC include/sl_vector.h)

set_target_properties(SL_STACK PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(SL_VECTOR PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main tests/main.cpp)

target_link_libraries(main PRIVATE SL_STACK)


