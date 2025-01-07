/*#include <iostream>
#include <string>
#include "sl_hashtable.h"

int main() {
    sl_hashtable<int, std::string> table = {{1, "ismail"}, {2, "khalid"}, {3, "walid"}};
    std::cout << "Element with index 1: " <<  table[1] << std::endl;
    std::cout << "Element with index 2: " <<  table[2] << std::endl;
    std::cout << "Element with index 3: " <<  table[3] << std::endl;
    return 0;
}*/

#include <catch2/matchers/catch_matchers_string.hpp>

#define CATCH_CONFIG_MAIN
#include <string>
#include <exception>
#include <iostream>
#include <catch2/catch_test_macros.hpp>

#include "sl_hashtable.h"

TEST_CASE("Hashtable basic operations", "[basic]") {
    sl_hashtable<int, double> table = {{1, 10.0}, {2, 20.0}, {3, 30.0}};

    REQUIRE(table[1] == 10.0);
    REQUIRE(table[2] == 20.0);
    REQUIRE(table[3] ==  30.0);
    REQUIRE(table.getSize() == 3);
    
    table.insert({{4, 40.0}, {5, 50.0}});


    REQUIRE(table.at(4) == 40.0);
    REQUIRE(table.at(5) == 50.0);
    REQUIRE(table.getSize() == 5);

    table.erase(1);
    REQUIRE(table.getSize() == 4);

    table.clear();
    REQUIRE(table.getSize() == 0);
}

TEST_CASE("Hashtable string operations", "[string]") {
    sl_hashtable<int, double> table = {{1, "ismai"}, {2, "khalid"}, {3, "abdarrahmane"}};

    CHECK_THAT(table[2], Catch::Matchers::Equals("Khalid"));
    REQUIRE(table.getSize() == 3);
    
    table.insert(4, "amine");

    REQUIRE(table.getSize() == 4);

    table.clear();
    REQUIRE(table.empty() == true);
}

