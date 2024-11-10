#include <iostream>
#include <string>
#include "../include/sl_stack.h"
#include "../include/sl_vector.h"

void stackTest() {
    sl_stack<std::string> cars;
    cars.stack_push("BMW");
    cars.stack_push("Audi");
    cars.stack_push("Alfa romeo");
    cars.stack_push("Mercides");

    int i=0;
    std::cout << "Size: " << cars.stack_size() << std::endl;
    std::cout << "Car 1: " << cars.stack_top() << std::endl;
    cars.stack_pop();
    std::cout << "Car 2: " << cars.stack_top() << std::endl;
    cars.stack_pop();
    std::cout << "Car 3: " << cars.stack_top() << std::endl;
    cars.stack_pop();
    std::cout << "Car 4: " << cars.stack_top() << std::endl;
    cars.stack_size();

}

int main(){
    sl_vector<std::string> cars;
    cars.displayInfo();
    cars.push_back("BMW");
    cars.push_back("Audi");
    cars.displayInfo();
    for (int i=0; i < cars.size() + 1; i++) {
        std::cout << "Element " << i << ": " << cars[i] << std::endl;
    } 
    cars.clear();
    cars.push_back("Mercedes");
    cars.displayInfo();
    std::cout << "Single element: " << cars[0] << std::endl;
    cars.displayInfo();
    return 0;
}
