#include <iostream>
#include <string>
#include "../include/sl_stack.h"
#include "../include/sl_vector.h"
#include "../include/sl_list.h"

int main(){
    sl_list<int> list {1, 2, 4, 5};
    std::cout << "Starting from Head: " << std::endl;
    list.displayListHead();
    std::cout << "First element: " << list.front() << std::endl;
    std::cout << "Last element: " << list.back() << std::endl;
    std::cout << "Poping the first element: " << std::endl;
    list.pop_front();
    list.displayListHead();
    std::cout << "======================" << std::endl;
    list.push_front(100);
    list.push_front(200);
    list.displayListHead();
    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Is the list empty ? " << list.empty() << std::endl;
    return 0;
}
