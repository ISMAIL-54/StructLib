#ifndef SL_VECTOR
#define SL_VECTOR
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <math.h>
#include <initializer_list>

template<typename sl_vector>
class vectorIterator {
    public:
        using valueType = typename sl_vector::valueType ;
        using pointerType = valueType*;
        using referenceType = valueType&;

    private:
        pointerType arr_ptr;

    public:
        vectorIterator() {
            arr_ptr = nullptr;
        }
        
        vectorIterator(pointerType ptr): arr_ptr(ptr) {}
        
        vectorIterator& operator++() {
            arr_ptr++;
            return *this;
        }

        vectorIterator operator++(int) {
            vectorIterator iterator = *this;
            ++(*this);
            return iterator;
        }
        
        vectorIterator& operator--() {
            arr_ptr--;
            return *this;
        }

        vectorIterator operator--(int) {
            vectorIterator iterator = *this;
            --(*this);
            return iterator;
        }

        referenceType operator[](size_t index) {
            return *(arr_ptr + index);
        }

        referenceType operator*() {
            return *arr_ptr;
        }

        pointerType operator->() {
            return arr_ptr;
        }

        vectorIterator operator+(size_t n) {
            vectorIterator iterator = *this;
            iterator.arr_ptr = arr_ptr + n;
            return iterator;
        }

        vectorIterator operator-(size_t n) {
            vectorIterator iterator = *this;
            iterator.arr_ptr = arr_ptr - n;
            return iterator;
        }

        vectorIterator& operator+=(size_t n) {
            arr_ptr += n;
            return *this;
        }

        vectorIterator& operator-=(size_t n) {
            arr_ptr -= n;
            return *this;
        }
        
        bool operator==(const vectorIterator& otherIterator) {
            return arr_ptr == otherIterator.arr_ptr;
        }

        bool operator!=(const vectorIterator& otherIterator) {
            return arr_ptr != otherIterator.arr_ptr;
        }

        bool operator<(const vectorIterator& otherIterator) {
            return arr_ptr < otherIterator.arr_ptr;
        }

        bool operator<=(const vectorIterator& otherIterator) {
            return arr_ptr <= otherIterator.arr_ptr;
        }

        bool operator>(const vectorIterator& otherIterator) {
            return arr_ptr > otherIterator.arr_ptr;
        }
        
        bool operator>=(const vectorIterator& otherIterator) {
            return arr_ptr >= otherIterator.arr_ptr;
        }
};

template<typename dataType>
class sl_vector {
    size_t currentSize = 0;
    size_t allocatedSize = 1;
    dataType* arr;

    void AllocateMemory() { 
        allocatedSize = pow(2, (int)log2(currentSize) + 1); 
        arr = (dataType*) malloc(allocatedSize * sizeof(dataType)); 
    }
    void ReallocateMemory() { 
        allocatedSize = pow(2, (int)log2(currentSize) + 1); 
        arr = (dataType*) realloc(arr, allocatedSize * sizeof(dataType)); 
    }
    
    public:
        using valueType = dataType;
        using iterator = vectorIterator<sl_vector<dataType>>;

        sl_vector(){ AllocateMemory(); }

        sl_vector(const std::initializer_list<dataType>& li) {
            currentSize = li.size();
            AllocateMemory();
            std::copy(li.begin(), li.end(), arr);
        }
        
        sl_vector(size_t size, dataType value) {
            currentSize = size;
            AllocateMemory();
            std::fill(arr, arr+size, value);
        }

        ~sl_vector() {
            free(arr);
        }
        
        void push_back(dataType element) {
            arr[currentSize++] = element;
            if (currentSize >= allocatedSize)
                ReallocateMemory();
        }

        void pop_back() {
            if (currentSize <= 0) {
                std::cerr << "Segmentation fault (core dumped)" << std::endl;
                exit(EXIT_FAILURE);
            }
            --currentSize;
        }

        size_t size() {
            return currentSize;
        }

        dataType front() {
            return arr[0];
        }

        dataType back() {
            return arr[currentSize-1];
        }

        bool empty() {
            if (currentSize == 0)
                return true;
            else
                return false;
        }

        size_t capacity() {
            return allocatedSize;
        }

        void clear() {
            currentSize = 0;
            free(arr);
            AllocateMemory();
        }

        dataType at(size_t index) {
            if (index >= currentSize)
                throw std::out_of_range("Index Out of Bounds"); 
            return arr[index];
        }

        dataType operator[](size_t index) {
            if (index >= currentSize) 
                throw std::out_of_range("Index Out of Bounds");
            return arr[index];
        }

        iterator begin() {
            return iterator(arr);
        }

        iterator end() {
            return iterator(arr + currentSize);
        }
};

#endif
