#ifndef SL_LIST
#define SL_LIST
#include <initializer_list>
#include <iostream>

// Doubly linked list: Node1 -> Node2 -> Node3

template<typename dataType>
struct Node {
    dataType data;
    Node<dataType>* nextNode;
    Node<dataType>* previousNode;
};

template<typename dataType>
class sl_list {
    Node<dataType>* head = nullptr; 
    Node<dataType>* tail = nullptr;
    size_t nodeCount = 0;

    public:
        sl_list() {
            head = new Node<dataType>;
        }

        sl_list(size_t size, dataType value) {
            Node<dataType>* ptr;
            Node<dataType>* node;
            nodeCount = 0;
            do {
                node = new Node<dataType>;
                node->data = value;
                nodeCount++;
                if (nodeCount == 1) {
                    node->previousNode = nullptr;
                    head = node;
                    ptr = node;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
            } while (nodeCount <= size - 1);
            tail = node;
            tail->nextNode = nullptr;
        }

        sl_list(const std::initializer_list<dataType>& li) {
            typename std::initializer_list<dataType>::iterator value = li.begin();
            nodeCount = li.size();
            Node<dataType>* ptr;
            Node<dataType>* node;
            do {
                node = new Node<dataType>;
                node->data = *value;
                if (value == li.begin()) {
                    node->previousNode = nullptr;
                    head = node;
                    ptr = node;
                    value++;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
                value++;
            } while (value != li.end());
            tail = node;
            tail->nextNode = nullptr;
        }

        ~sl_list() {
            free(head);
            free(tail);
        }

        void push_front(dataType element) {
            Node<dataType>* node = new Node<dataType>{element};
            head->previousNode = node;
            node->nextNode = head;
            head = node;
            head->previousNode = nullptr;
            nodeCount+=1;
        }

        void push_back(dataType element) {
            Node<dataType>* node = new Node<dataType>{element};
            tail->nextNode = node;
            node->previousNode = tail;
            tail = node;
            tail->nextNode = nullptr;
            nodeCount++;
        }

        void pop_front() {
            Node<dataType>* ptr = head->nextNode;
            delete head;
            ptr->previousNode = nullptr;
            head = ptr;
            nodeCount--;
        }

        void pop_back() {
            Node<dataType>* ptr = tail->previousNode;
            delete tail;
            ptr->nextNode = nullptr;
            tail = ptr;
            nodeCount--;
        }
            
        dataType front() {
            return head->data;
        }

        dataType back() {
            return tail->data;
        }

        size_t size() {
            return nodeCount;
        }

        bool empty() {
            if (nodeCount == 0)
                return true;
            else
                return false;
        }

        void displayListHead() {
           Node<dataType>* ptr = head;
           for (int i=1; i <= nodeCount; i++) {
               std::cout << "Address: " << ptr << " - ";
               std::cout << "Value " << i << ": " << ptr->data << std::endl;
               ptr = ptr->nextNode;
            }
        }


        void displayListTail() {
            Node<dataType>* ptr = tail;
            for (int i=nodeCount; i > 0; i--) {
                std::cout << "Address: " << ptr << " - ";
                std::cout << "Value: " << i << ": " << ptr->data << std::endl;
                ptr = ptr->previousNode;
            }
        }

};

#endif
