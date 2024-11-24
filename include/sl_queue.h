#ifndef SL_QUEUE 
#define SL_QUEUE 
#include <cmath>
#include <iostream>

template<class dataType>
class sl_queue { 
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
        sl_queue() {
            nbElement = 0;
            capacity = 1;
            AllocateMemory();
        }

        ~sl_queue() {
            free(arr); 
        } 

        void push(dataType element) { 
            arr[nbElement++] = element;
            if (nbElement >= capacity) 
                ReallocateMemory();
        }

        void pop() {
            if (nbElement <= 0) {
                std::cerr << "Error: queue underflow!" << std::endl;
                exit(EXIT_FAILURE);
            }
            for (int i=1; i < nbElement; i++) {
                arr[i-1] = arr[i];
            }
            --nbElement;
        }

        dataType front() {
            if (nbElement == 0) {
                std::cerr << "Queue is empty!" << std::endl;
                exit(EXIT_FAILURE);
            }
            return arr[0];
        }

        dataType back() {
            if (nbElement == 0) {
                std::cerr << "Queue is empty!" << std::endl;
                exit(EXIT_FAILURE);
            }
            return arr[nbElement-1];
        }

        bool isEmpty() {
            if (nbElement > 0)
                return false;
            else 
                return true;
        }

        size_t size() {
            return nbElement;
        }

};

#endif

