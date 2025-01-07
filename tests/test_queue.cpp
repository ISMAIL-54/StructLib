#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
#include "sl_queue.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE("Queue basic operations", "[basic]") {
    sl_queue<int> Q;

    Q.push(10);
    Q.push(20);
    Q.push(40);

    REQUIRE(Q.isEmpty() == false);
    REQUIRE(Q.front() == 10);
    REQUIRE(Q.size() == 3);

    Q.pop();

    REQUIRE(Q.front() == 20);

    Q.pop();

    REQUIRE(Q.front() == 40);

    Q.pop();

    REQUIRE(Q.size() == 0);
    REQUIRE(Q.isEmpty() == true);
}

TEST_CASE("Queue string operations", "[string]") {
    sl_queue<std::string> Q;

    Q.push("Orange");
    Q.push("Car");
    Q.push("Key");

    REQUIRE(Q.size() == 3);

    CHECK_THAT(Q.back(), Catch::Matchers::Equals("Key"));
    CHECK_THAT(Q.front(), Catch::Matchers::Equals("Orange"));

    Q.pop();
    Q.pop();

    CHECK_THAT(Q.back(), Catch::Matchers::Equals("Orange"));

    REQUIRE(Q.size() == 1);
    REQUIRE(Q.isEmpty() == false);
}
