file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(tests ${TEST_SOURCES})

target_link_libraries(tests PRIVATE ${PROJECT_NAME} Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(tests)
