#include <iostream>
#include <string>
#include "../include/sl_stack.h"
#include "../include/sl_vector.h"
#include "../include/sl_list.h"
#include "../include/sl_forward_list.h"

struct Student {
    std::string name;
    double score;
};

int main(){
    sl_list<int> numbers1 = {0, 0, 0, 20, 0, 0, 300};
    sl_list<int> numbers2;
    numbers1.displayListHead();
    std::cout << "-----------------" << std::endl;
    numbers1.unique();
    numbers1.displayListHead();
    return 0;
}
