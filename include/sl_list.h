/*#ifndef SL_LIST
#define SL_LIST
#include <initializer_list>
#include <iostream>

// Doubly linked list: Node1 -> Node2 -> Node3

template<typename sl_list>
class listIterator {
    public:
        using valueType = typename sl_list::valueType;
        using nodeType = typename sl_list::nodeType;
        using pointerType = nodeType*;
        using referenceType = nodeType&;

    private:
        pointerType head;
        pointerType tail;
        pointerType node_ptr;

    public:
        listIterator() {
            node_ptr = nullptr;
        }

        listIterator(pointerType ptr) {
            if (ptr->nextNode == nullptr)
                tail = ptr;
            else
                head = ptr;
            node_ptr = ptr;
        }
        
        listIterator& operator++() {
            if (node_ptr->nextNode == nullptr) {
                tail = node_ptr;
                node_ptr = head;
            } else
                node_ptr = node_ptr->nextNode;     
            return *this;
        }
         
        listIterator operator++(int) {
            listIterator iterator = *this;
            if (node_ptr->nextNode == nullptr) {
                tail = node_ptr;
                node_ptr = head;
            } else
                node_ptr = node_ptr->nextNode;
            return iterator; 
        }

        listIterator& operator--() {
            if (node_ptr->previousNode == nullptr) {
                head = node_ptr;
                node_ptr = tail;
            } else
                node_ptr = node_ptr->previousNode;
            return *this;
        }

        listIterator operator--(int) {
           listIterator iterator = *this;
           if (node_ptr->previousNode == nullptr) {
               head = node_ptr;
               node_ptr = tail;
            } else
                node_ptr = node_ptr->previousNode;
            return iterator;
        }

        valueType operator*() {
            return node_ptr->data;
        }
        
        pointerType operator->() {
            return node_ptr;
        }

        bool operator==(const listIterator& otherIterator) {
            return node_ptr == otherIterator.node_ptr;
        }

        bool operator!=(const listIterator& otherIterator) {
            return node_ptr != otherIterator.node_ptr;
        }
};

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
        using valueType = dataType;
        using nodeType = Node<dataType>;
        using iterator = listIterator<sl_list<dataType>>;

        sl_list() {
            head = new Node<dataType>;
            tail = head;
        }

        sl_list(size_t size, dataType value) {
            Node<dataType>* ptr;
            Node<dataType>* node;
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
            Node<dataType>* temp = head->nextNode;
            while (head != nullptr) {
                delete(head);
                head = temp;
                temp = temp->nextNode;
            }
            delete(head);
            nodeCount = 0;
        }

        void push_front(dataType element) {
            if (nodeCount == 0) {
                head->data = element;
                head->previousNode = nullptr;
                head->nextNode = nullptr;
                nodeCount++;
                return;
            }
            Node<dataType>* node = new Node<dataType>;
            node->data = element;
            head->previousNode = node;
            node->nextNode = head;
            head = node;
            head->previousNode = nullptr;
            nodeCount++;
        }

        void push_back(dataType element) {
            if (nodeCount == 0) {
                tail->data = element;
                tail->previousNode = nullptr;
                tail->nextNode = nullptr;
                nodeCount++;
                return;
            }
            Node<dataType>* node = new Node<dataType>;
            node->data = element;
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

        void clear() {
            Node<dataType>* ptr = head->nextNode;;
            for (int i=2; i < nodeCount; i++) {
                if (ptr->nextNode == nullptr) {
                    delete(ptr);
                    ptr = nullptr;
                    break;
                }
                ptr = ptr->nextNode;
                delete(ptr->previousNode);
                ptr->previousNode = nullptr;
            }
            delete(head);
            delete(tail);
            head = nullptr;
            tail = nullptr;
            nodeCount = 0;
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(tail);
        }

        void displayListHead() {
           Node<dataType>* ptr = head;
           int i=1;
           while (ptr != nullptr) {
               std::cout << " Address: " << ptr << " - ";
               std::cout << "Value " << i << ": " << ptr->data << std::endl;
               ptr = ptr->nextNode;
               i++;
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

#endif*/
