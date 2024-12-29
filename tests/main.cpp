#include <iostream>
#include <string>
#include "sl_hashtable.h"

int main(){
    sl_hashtable<std::string, int> numbers = {
        {"One", 1},
        {"Two", 2},
        {"Three", 3},
        {"Four", 4},
        {"23", 23},
        {"10", 10},
        {"Blah", 100},
        {"Hundred", 100},
        {"Thousand", 1000},
        {"Seven", 7},
        {"dsf", 234},
        {"Other", 100},
    };

    std::cout << "========================" << std::endl;
    numbers.displayHashTable();
    std::cout << "Size: " << numbers.getSize() << std::endl;
    std::cout << "Other exists ? " << numbers.count("Other") << std::endl;
    return 0;
}

/*  
 *              1
 *          4    42
 *      12   2 
 *
 *
 *     [1, 4, 42,   
 * */

