#include <iostream>
#include <string>
#include "../include/sl_stack.h"
#include "../include/sl_vector.h"
#include "../include/sl_list.h"
#include "../include/sl_forward_list.h"

int main(){
    sl_forward_list<int> list {20, 3, 5, 0, 10, 1, -333, 1};
    sl_forward_list<int>::iterator iter1 = list.begin();
    sl_forward_list<int>::iterator iter2 = list.end();
    list.displayList();
    list.erase_after(iter1, iter2);
    std::cout << "====================" << std::endl;
    list.displayList();
    return 0;
}
