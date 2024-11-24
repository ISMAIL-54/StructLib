#ifndef SL_LIST
#define SL_LIST
#include <algorithm>
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

        listIterator(pointerType ptr, pointerType head, pointerType tail): node_ptr(ptr), head(head), tail(tail) {}
        
        listIterator& operator++() {
            if (node_ptr == nullptr)
                node_ptr = head;
            else if (node_ptr->nextNode == nullptr) {
                tail = node_ptr;
                node_ptr = nullptr;
            } else
                node_ptr = node_ptr->nextNode;     
            return *this;
        }
         
        listIterator operator++(int) {
            listIterator iterator = *this;
            ++(*this);
            return iterator; 
        }

        listIterator& operator--() {
            if (node_ptr == nullptr)
                node_ptr = tail;
            else if (node_ptr->previousNode == nullptr) {
                head = node_ptr;
                node_ptr = tail;
            } else
                node_ptr = node_ptr->previousNode;
            return *this;
        }

        listIterator operator--(int) {
           listIterator iterator = *this;
           --(*this);
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
struct D_Node {
    dataType data;
    D_Node<dataType>* nextNode;
    D_Node<dataType>* previousNode;
};

template<typename dataType>
class sl_list {
    D_Node<dataType>* head; 
    D_Node<dataType>* tail;
    size_t nodeCount;

    public:
        using valueType = dataType;
        using nodeType = D_Node<dataType>;
        using iterator = listIterator<sl_list<dataType>>;

        sl_list() {
            head = nullptr;
            tail = head;
            nodeCount = 0;
        }

        sl_list(const size_t& size, const dataType& value) {
            nodeType* ptr;
            nodeType* node;
            nodeCount = 0;
            while (nodeCount < size) {
                node = new nodeType{value, nullptr, nullptr};
                nodeCount++;
                if (nodeCount == 1) {
                    head = node;
                    ptr = node;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
            }
            tail = node;
        }

        sl_list(const std::initializer_list<dataType>& li) {
            typename std::initializer_list<dataType>::iterator value = li.begin();
            nodeCount = li.size();
            nodeType* ptr;
            nodeType* node;
            while (value != li.end()) {
                node = new nodeType{*value, nullptr, nullptr};
                if (value == li.begin()) {
                    head = node;
                    ptr = node;
                    value++;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
                value++;
            }
            tail = node;
        }

        void push_front(dataType element) {
            if (nodeCount == 0) {
                head = new nodeType{element, nullptr, nullptr};
                tail = head;
                nodeCount++;
                return;
            }
            nodeType* node = new nodeType{element, head, nullptr};
            head->previousNode = node;
            head = node;
            nodeCount++;
        }

        void push_back(dataType element) {
            if (nodeCount == 0) {
                head = new nodeType{element, nullptr, nullptr};
                tail = head;
                nodeCount++;
                return;
            }
            nodeType* node = new nodeType{element, nullptr, tail};
            tail->nextNode = node;
            tail = node;
            nodeCount++;
        }

        void pop_front() {
            if (nodeCount == 1) {
                delete head;
                head = nullptr;
                nodeCount--;
                return;
            }
           nodeType* temp = head->nextNode;
            delete head;
            temp->previousNode = nullptr;
            head = temp;
            nodeCount--;
        }

        void pop_back() {
            if (nodeCount == 1) {
                delete head;
                head = nullptr;
                nodeCount--;
                return;
            }
            nodeType* temp = tail->previousNode;
            delete tail;
            temp->nextNode = nullptr;
            tail = temp;
            nodeCount--;
        }

        void clear() {
            nodeCount = 0;
            nodeType* node = tail;
            while (node != nullptr) {
                nodeType* temp = node->previousNode;
                delete node;
                node = temp;
            }
            head = nullptr;
            tail = nullptr;
        }

        void assign(const size_t& n, const dataType& val) {
            this->clear();
            nodeType* node;
            nodeType* ptr;
            while (nodeCount < n) {
                node = new nodeType{val, nullptr, nullptr};
                nodeCount++;
                if (nodeCount == 1) {
                    head = node;
                    ptr = node;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
            }
            tail = node;
        }

        void assign(const std::initializer_list<dataType>& li) {
            this->clear();
            nodeCount = li.size();
            typename std::initializer_list<dataType>::iterator iter = li.begin();
            nodeType* node;
            nodeType* ptr;
            while (iter != li.end()) {
                node = new nodeType{*iter, nullptr, nullptr};
                if (iter == li.begin()) {
                    head = node;
                    ptr = node;
                    ++iter;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
                ++iter;
            }
            tail = node;
        }

        void assign(const iterator& iterBeg, const iterator& iterEnd) {
            this->clear();
            nodeType* node;
            nodeType* ptr;
            iterator iter = iterBeg;
            while (iter != iterEnd) {
                node = new nodeType{*iter, nullptr, nullptr}; 
                nodeCount++;
                if (iter == iterBeg) {
                    head = node;
                    ptr = node;
                    ++iter;
                    continue;
                }
                node->previousNode = ptr;
                ptr->nextNode = node;
                ptr = node;
                ++iter;
            }
            tail = node;
        }

        iterator insert(const iterator& pos, const size_t& n, const dataType& element) {
            nodeType* node;
            size_t cntr = 0;
            iterator iter = pos;
            while (cntr < n) {
                insert(iter, element);
                iter++;
                cntr++;
            }
            iter = pos;
            iter++;
            return iter;
        }

        iterator insert(const iterator& pos, const dataType& element) {
            if (nodeCount == 0) {
                std::cerr << "Segmentation fault (core dumped)" << std::endl;
                exit(EXIT_FAILURE);
            }
            iterator iter = pos;
            nodeType* node = new nodeType{element, nullptr, nullptr};
            node->nextNode = iter->nextNode;
            if (iter->nextNode == nullptr) {
                nodeType* temp = iter->previousNode;
                node->previousNode = temp->nextNode;
                tail = node;
            } else {
                nodeType* temp = iter->nextNode;
                node->previousNode = temp->previousNode;
                temp->previousNode = node;
            }
            iter->nextNode = node;
            nodeCount++;
            iter++;
            return iter;
        }

        void erase(iterator pos) {
            if (nodeCount == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            } 

            if (pos->nextNode == nullptr) {
                nodeType* temp = pos->previousNode;
                tail = temp;
                delete temp->nextNode;
                temp->nextNode = nullptr;
            } else if (pos->previousNode == nullptr) {
                nodeType* temp = pos->nextNode;
                head = temp;
                delete temp->previousNode;
                temp->previousNode = nullptr;
            } else {
                nodeType* nex = pos->nextNode;
                nodeType* prev = pos->previousNode;
                delete prev->nextNode;
                nex->previousNode = prev;
                prev->nextNode = nex;
            }
        }

        void reverse() {
            nodeType* node = head;
            while (node != nullptr) {
                nodeType* nex = node->nextNode;
                nodeType* prev = node->previousNode;
                node->nextNode = prev;
                node->previousNode = nex;
                if (node->previousNode == nullptr)
                    head = node;
                else if (node->nextNode == nullptr)
                    tail = node;
                node = nex;
            }
        }

        void remove(dataType val) {
            nodeType* node = head;
            while (node != nullptr) {
                if (node->data == val) {
                    nodeCount--;
                    if (node == head) {
                        head = node->nextNode;
                        head->previousNode = nullptr;
                        delete node;
                        node = head;
                        continue;
                    } else if (node == tail) {
                        tail = node->previousNode;
                        tail->nextNode = nullptr;
                        delete node;
                        node = tail;
                        continue;
                    }
                    nodeType* prev = node->previousNode;
                    nodeType* nex = node->nextNode;
                    prev->nextNode = node->nextNode;
                    nex->previousNode = prev;
                    delete node;
                    node = nex;
                } else 
                    node = node->nextNode;
            }
        }

        void unique() {
            nodeType* node = head;
            while (node != tail) {
                nodeType* nex = node->nextNode;
                if (node->data == nex->data) {
                    node->nextNode = nex->nextNode;
                    if (nex == tail)
                        tail = node;
                    else {
                        nodeType* temp = nex->nextNode;
                        temp->previousNode = node;
                    }
                    delete nex;
                    nex = nullptr;
                    nodeCount--;
                } else
                    node = node->nextNode;
            }
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

        iterator begin() {
            return iterator(head, head, tail);
        }

        iterator end() {
            return iterator(nullptr, head, tail);
        }

};

#endif
