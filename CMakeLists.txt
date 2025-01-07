cmake_minimum_required(VERSION 3.10) 

project(StructLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

include_directories(include)

add_library(${PROJECT_NAME} include)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

add_subdirectory(tests)
