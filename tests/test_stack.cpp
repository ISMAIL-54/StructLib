#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "sl_stack.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Stack basic operations", "[basic]") {
    sl_stack<double> stack_num;

    stack_num.push(10.0);
    stack_num.push(20.0);
    stack_num.push(40.0);

    REQUIRE(stack_num.isEmpty() == false);
    REQUIRE(stack_num.top() == 40.0);
    REQUIRE(stack_num.size() == 3);

    stack_num.pop();

    REQUIRE(stack_num.top() == 20.0);

    stack_num.pop();

    REQUIRE(stack_num.top() == 10.0);

    stack_num.pop();

    REQUIRE(stack_num.size() == 0);
    REQUIRE(stack_num.isEmpty() == true);
}

TEST_CASE("Stack string operations", "[string]") {
    sl_stack<std::string> stack_str;

    stack_str.push("Hello");
    stack_str.push("word");
    stack_str.push("value");

    REQUIRE(stack_str.size() == 3);

    CHECK_THAT(stack_str.top(), Catch::Matchers::Equals("value"));

    stack_str.pop();
    stack_str.pop();

    CHECK_THAT(stack_str.top(), Catch::Matchers::Equals("Hello"));

    REQUIRE(stack_str.size() == 1);
    REQUIRE(stack_str.isEmpty() == false);
}
