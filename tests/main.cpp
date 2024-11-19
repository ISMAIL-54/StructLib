#include <iostream>
#include <string>
#include "../include/sl_stack.h"
#include "../include/sl_vector.h"
#include "../include/sl_list.h"
#include "../include/sl_forward_list.h"

int main(){
    sl_forward_list<int> list {10, 20, 40, 50, 200, 20, 30};
    list.displayList();
    list.remove(20);
    std::cout << "==================" << std::endl;
    list.displayList();
    return 0;
}
