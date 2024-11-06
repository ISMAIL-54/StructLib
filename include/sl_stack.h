#ifndef SL_STACK 
#define SL_STACK 
#include <iostream>

template<class dataType>
class SLStack { 
    private:
        int size;
        dataType* arr;

    public:
        SLStack() {
            size = 0;
            arr = new dataType[100];
        }

        ~SLStack() {
            delete[] arr;
        }

        dataType stack_top() {
            if (size == 0){
                std::cerr << "Error: stack is empty!" << std::endl;
            }
            return arr[size-1];
        }
        void stack_push(dataType element) {
            if (size >= 99) {
                std::cerr << "Error: stack overflow!" << std::endl;
            }
            arr[size++] = element;
        }
        void stack_pop() {
            if (size <= 0) {
                std::cerr << "Error: stack underflow!" << std::endl;
            }
            arr[--size] = 0;
        }
        bool stack_isEmpty() {
            if (size > 0)
                return false;
            else 
                return true;
        }
        bool stack_isFull() {
            if (size >= 99)
                return true;
            else
                return false;
        }
        int stack_size() {
            return size;
        }
};

#endif

