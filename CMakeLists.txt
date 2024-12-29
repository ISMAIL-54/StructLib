cmake_minimum_required(VERSION 3.30)

project(StructLib)

include_directories(include)

add_library(SL STATIC include)

set_target_properties(SL PROPERTIES LINKER_LANGUAGE CXX)

add_executable(main tests/main.cpp)

target_link_libraries(main PRIVATE SL)


