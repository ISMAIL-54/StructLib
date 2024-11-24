#include <iostream>
#include <string>
#include "../include/sl_queue.h"
#include "../include/sl_stack.h"

int main(){
    sl_stack<int> numbers;
    numbers.push(20);
    numbers.displayData();
    std::cout << "---------------" << std::endl;
    numbers.push(10);
    numbers.displayData();
    std::cout << "---------------" << std::endl;
    numbers.push(30);
    numbers.displayData();
    std::cout << "---------------" << std::endl;
    numbers.pop();
    numbers.displayData();
    std::cout << "---------------" << std::endl;
    numbers.pop();
    numbers.displayData();
    std::cout << "---------------" << std::endl;
    numbers.pop();
    numbers.displayData();
    std::cout << "---------------" << std::endl;

    std::cout << numbers.top() << std::endl;
    return 0;
}
