#include <catch2/matchers/catch_matchers_string.hpp>
#define CATCH_CONFIG_MAIN
#include <string>
#include <iostream>
#include <catch2/catch_test_macros.hpp>

#include "sl_list.h"

TEST_CASE("List basic operations", "[basic]") {
    sl_list<int> li;

    li.push_back(10);
    li.push_back(20);
    li.push_back(40);

    REQUIRE(li.empty() == false);

    REQUIRE(li.front() == 10);
    REQUIRE(li.back() == 40);

    REQUIRE(li.size() == 3);

    REQUIRE(li.front() == 10);
    REQUIRE(li.back() == 40);

    li.pop_back();

    REQUIRE(li.back() == 20);

    li.pop_back();
    li.pop_back();

    REQUIRE(li.size() == 0);
    REQUIRE(li.empty());
}

/*TEST_CASE("List string operations", "[string]") {
    sl_list<std::string> li;
    sl_list<std::string>::iterator it = li.begin();

    li.push_back("Emm");
    li.push_back("Sick");
    li.push_back("Another string");

    REQUIRE(li.size() == 3);

    CHECK_THAT(*it, Catch::Matchers::Equals("Emm"));
    it++;
    CHECK_THAT(*it, Catch::Matchers::Equals("Sick"));
    it++;
    CHECK_THAT(*it, Catch::Matchers::Equals("Another string"));
    
    li.pop_back();
    li.pop_back();

    REQUIRE(li.size() == 1);
    REQUIRE(li.empty() == false);
}*/

TEST_CASE("List iterators", "[iterators]") {
    sl_list<int> numbers = {1, 2, 3, 4};
    sl_list<int>::iterator iter = numbers.begin();

    for (int i=1; iter != numbers.end(); iter++, i++)
        REQUIRE((*iter) == i);
}

