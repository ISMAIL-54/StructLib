#include <iostream>
#include <string>
#include "../include/sl_stack.h"
#include "../include/sl_vector.h"
#include "../include/sl_list.h"

int main(){
    sl_vector<std::string> cars {"BMW", "Audi", "C++"};

    sl_vector<std::string>::iterator iter1 = cars.begin();
    sl_vector<std::string>::iterator iter2 = cars.begin();
    std::cout << "iter1 == iter2 (true) : " << (iter1 == iter2) << std::endl;
    std::cout << "iter1 != iter2 (false) : " << (iter1 != iter2) << std::endl;
    iter2++;
    std::cout << "iter1 <= iter2 (true) : " << (iter1 <= iter2) << std::endl;
    std::cout << "iter1 < iter2 (true) : " << (iter1 < iter2) << std::endl;
    iter2--;
    std::cout << "iter1 >= iter2 (true) : " << (iter1 >= iter2) << std::endl;
    std::cout << "iter1 > iter2 (false) : " << (iter1 > iter2) << std::endl;

    iter1+=1;
    std::cout << "Should print 'Audi' => " << *iter1 << std::endl;
    iter1-=1;
    std::cout << "Should print 'BMW' => " << *iter1 << std::endl;
    return 0;
}
