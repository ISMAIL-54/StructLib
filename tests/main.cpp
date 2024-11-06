#include <iostream>
#include "sl_stack.h"

int main(){
    SLStack<int> firstStack;
    firstStack.stack_push(100);
    firstStack.stack_push(200);
    firstStack.stack_push(300);

    
    std::cout << firstStack.stack_top() << std::endl; // 300
    firstStack.stack_pop();
    std::cout << firstStack.stack_top() << std::endl; // 200
    return 0;
}
