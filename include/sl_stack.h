#ifndef SL_STACK 
#define SL_STACK 
#include <cmath>
#include <iostream>

template<class dataType>
class sl_stack { 
        size_t nbElement;
        size_t capacity;
        dataType* arr;
        void AllocateMemory() { 
            capacity = pow(2, (int)log2(nbElement) + 1);
            arr = (dataType*) malloc(capacity * sizeof(dataType)); }
        void ReallocateMemory() { 
            capacity = pow(2, (int)log2(nbElement) + 1);
            arr = (dataType*) realloc(arr, capacity * sizeof(dataType)); 
        }

    public:
        sl_stack() {
            nbElement = 0;
            capacity = 1;
            AllocateMemory();
        }

        ~sl_stack() {
            free(arr);
        }

        dataType top() {
            if (nbElement == 0){
                std::cerr << "Stack is empty!" << std::endl;
                exit(EXIT_FAILURE);
            }
            return arr[nbElement-1];
        }

        void push(dataType element) {
            arr[nbElement++] = element;
            if (nbElement >= capacity) 
                ReallocateMemory();
        }

        void pop() {
            if (nbElement <= 0) {
                std::cerr << "Error: stack underflow!" << std::endl;
                exit(EXIT_FAILURE);
            }
            --nbElement;
        }

        bool isEmpty() {
            return (nbElement == 0) ? true : false;
        }

        int size() {
            return nbElement;
        }
};

#endif

