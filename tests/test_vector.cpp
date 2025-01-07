#include <catch2/matchers/catch_matchers_string.hpp>
#define CATCH_CONFIG_MAIN
#include <string>
#include <exception>
#include <iostream>
#include <catch2/catch_test_macros.hpp>

#include "sl_vector.h"

TEST_CASE("Vector basic operations", "[basic]") {
    sl_vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(40);

    REQUIRE(vec.empty() == false);

    REQUIRE(vec[0] == 10);
    REQUIRE(vec[1] == 20);
    REQUIRE(vec[2] == 40);

    REQUIRE(vec.at(0) == 10);
    REQUIRE(vec.at(1) == 20);
    REQUIRE(vec.at(2) == 40);

    REQUIRE(vec.size() == 3);

    REQUIRE(vec.front() == 10);
    REQUIRE(vec.back() == 40);

    vec.pop_back();

    REQUIRE(vec.back() == 20);

    vec.pop_back();
    vec.pop_back();

    REQUIRE(vec.size() == 0);
    REQUIRE(vec.empty());
}

/*TEST_CASE("Vector string operations", "[string]") {
    sl_vector<std::string> vec;

    vec.push_back("Hello");
    vec.push_back("word");
    vec.push_back("value");

    REQUIRE(vec.size() == 3);

    CHECK_THAT(vec.at(0), Catch::Matchers::Equals("Hello"));
    CHECK_THAT(vec.at(1), Catch::Matchers::Equals("word"));
    CHECK_THAT(vec.at(2), Catch::Matchers::Equals("value"));
    
    vec.pop_back();
    vec.pop_back();

    REQUIRE(vec.size() == 1);
    REQUIRE(vec.empty() == false);
}*/

TEST_CASE("Vector iterators", "[iterators]") {
    sl_vector<int> numbers = {1, 2, 3, 4};
    sl_vector<int>::iterator iter = numbers.begin();

    for (int i=1; iter != numbers.end(); iter++, i++)
        REQUIRE((*iter) == i);
}
