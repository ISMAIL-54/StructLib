#ifndef SL_FORWARD_LIST
#define SL_FORWARD_LIST
#include <initializer_list>
#include <iostream>
#include <cstddef>

template <typename sl_forward_list>
class forwardListIterator {
    public:
        using valueType = typename sl_forward_list::valueType;
        using nodeType = typename sl_forward_list::nodeType;
        using pointerType = nodeType*;
        using referenceType = nodeType&;

    private:
        pointerType node_ptr;

    public:
        forwardListIterator() {
            node_ptr = nullptr;
        }

        forwardListIterator(pointerType ptr) {
            node_ptr = ptr;   
        }

        forwardListIterator& operator++() {
            node_ptr = node_ptr->nextNode;
            return *this;
        }

        forwardListIterator operator++(int) {
            forwardListIterator iterator = *this;
            ++(*this);
            return iterator;
        }

        valueType operator*() {
            return node_ptr->data;
        }

        pointerType operator->() {
            return node_ptr;
        }

        bool operator==(const forwardListIterator& otherIterator) {
            return this->node_ptr == otherIterator.node_ptr;
        }

        bool operator!=(const forwardListIterator& otherIterator) {
            return this->node_ptr != otherIterator.node_ptr;
        }
};

template<typename dataType>
struct Node {
    dataType data;
    Node<dataType>* nextNode;
};

template<typename dataType>
class sl_forward_list {
    Node<dataType>* head = nullptr;
    Node<dataType>* tail = nullptr;
    size_t nodeCount = 0;

    public:
        using valueType = dataType;
        using nodeType = Node<dataType>;
        using iterator = forwardListIterator<sl_forward_list<dataType>>;

        sl_forward_list() {
            head = new nodeType;
            tail = head;
        }

        sl_forward_list(const size_t& size, const dataType& value) {
            nodeType* node;
            nodeType* ptr;
            while (nodeCount < size) {
                node = new nodeType{value, nullptr};
                nodeCount++;
                if (nodeCount == 1) {
                    head = node;
                    ptr = node;
                    tail = node;
                    continue;
                }
                ptr->nextNode = node;
                ptr = node;
            }
            tail = node;
        }

        sl_forward_list(const std::initializer_list<dataType>& li) {
            nodeCount = li.size();
            typename std::initializer_list<dataType>::iterator iter = li.begin();
            nodeType* node;
            nodeType* ptr;
            while (iter != li.end()) {
                node = new nodeType{*iter, nullptr};
                if (iter == li.begin()) {
                    head = node;
                    tail = node;
                    ptr = node;
                    ++iter;
                    continue;
                }
                ptr->nextNode = node;
                ptr = node;
                ++iter;
            }
            tail = node;
        }

        void push_front(dataType element) {
            if (nodeCount == 0) {
                head->data = element;
                head->nextNode = nullptr;
                nodeCount++;
                return;
            }
            nodeType* node = new nodeType{element, head};
            head = node;
            nodeCount++;
        }

        void push_back(dataType element) {
            if (nodeCount == 0) {
                head->data = element;
                head->nextNode = nullptr;
                nodeCount++;
                return;
            }
            nodeType* node = new nodeType{element, nullptr};
            tail->nextNode = node;
            tail = node;
            nodeCount++;
        }

        void pop_front() {
            if (nodeCount == 1) {
                delete head;
                nodeCount--;
                return;
            }
            nodeType* temp = head;
            head = head->nextNode;
            delete temp;
            temp = nullptr;
            nodeCount--;
        }

        void pop_back() {
            if (nodeCount == 1) {
                delete head;
                nodeCount--;
                return;
            }
            nodeType* temp = tail;
            delete temp;
            temp = nullptr;
            nodeType* ptr = head;
            for (int i=1; i <= nodeCount - 2; i++) {
                ptr = ptr->nextNode;    
            }
            tail = ptr;
            tail->nextNode = nullptr;
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
            if (nodeCount <= 1) {
               delete head;
               nodeCount = 0;
               return;
            }
            nodeType* temp = head;
            while (nodeCount > 0) {
                head = head->nextNode;
                delete temp;
                temp = nullptr;
                temp = head;
                nodeCount--;
            }
            head = new nodeType;
            tail = head;
        }

        void assign(const size_t& n, const dataType& val) {
            this->clear();
            nodeType* node;
            nodeType* ptr;
            while (nodeCount < n) {
                node = new nodeType{val, nullptr};
                nodeCount++;
                if (nodeCount == 1) {
                    head = node;
                    ptr = node;
                    tail = node;
                    continue;
                }
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
                node = new nodeType{*iter, nullptr};
                if (iter == li.begin()) {
                    head = node;
                    tail = node;
                    ptr = node;
                    ++iter;
                    continue;
                }
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
                node = new nodeType{*iter, nullptr}; 
                nodeCount++;
                if (iter == iterBeg) {
                    head = node;
                    tail = node;
                    ptr = node;
                    ++iter;
                    continue;
                }
                ptr->nextNode = node;
                ptr = node;
                ++iter;
            }
            tail = node;
        }

        void insert_after(iterator pos, const dataType& element) {
            if (nodeCount == 0) {
                std::cerr << "Segmentation fault (core dumped)" << std::endl;
                exit(EXIT_FAILURE);
            }
            nodeType* node = new nodeType{element, pos->nextNode};
            if (pos->nextNode == nullptr)
                tail = node;
            pos->nextNode = node;
            nodeCount++;
        }

        void insert_after(const iterator& pos, const size_t& n, const dataType& element) {
            nodeType* node;
            size_t cntr = 0;
            iterator iter = pos;
            while (cntr < n) {
                insert_after(iter, element);
                iter++;
                cntr++;
            }
        }

        void insert_after(const iterator& pos, const iterator& iterBeg, const iterator& iterEnd) {
            iterator iter = iterBeg;
            iterator posIter = pos;
            while (iter != iterEnd) {
                insert_after(posIter, *iter);
                posIter++;
                iter++;
            }
        }
        
        void reverse() {
            if (nodeCount <= 1)
                return;
            nodeType* node = head->nextNode;
            nodeType* next;
            nodeType* previous = head;
            tail = head;
            tail->nextNode = nullptr;
            for (int i=2; i <= nodeCount; i++) {
                next = node->nextNode;
                node->nextNode = previous;
                if (next == nullptr) {
                    head = node;
                    break;
                }
                previous = node;
                node = next;
            }
            head = node;
        }

        void erase_after(iterator& pos) {
            iterator iter = pos;
            ++iter;
            nodeType* temp = pos->nextNode;
            pos->nextNode = iter->nextNode; 
            delete temp;
            temp = nullptr;
            nodeCount--;

            temp = head;
            while (temp != nullptr) {
               if (temp->nextNode == nullptr)
                   tail = temp;
               temp = temp->nextNode;
            }
        }

        void erase_after(iterator& start, iterator& end) {
            iterator iter = start;
            while (iter != end) {
                if (start->nextNode == nullptr) {
                    tail = head;
                    tail->nextNode = nullptr;
                    break;
                }
                nodeType* temp = start->nextNode;
                start->nextNode = temp->nextNode;
                delete temp;
                temp = nullptr;
                nodeCount--;
                iter = start;
            }
        }

        void unique() {
           nodeType* node = head;
           while (node->nextNode != nullptr) {
                nodeType* temp = node->nextNode;
                if (node->data == temp->data) {
                    if (temp->nextNode == nullptr)
                        tail = node;
                    node->nextNode = temp->nextNode;
                    delete temp;
                    temp = nullptr;
                    nodeCount--;
                } else 
                    node = node->nextNode;
           }
        }

        void remove(dataType element) {
            nodeType* prev = head;
            nodeType* curr = head;
            while (curr != nullptr) {
                nodeType* temp;
                if (curr->data == element) {
                    if (curr == head)
                        head = head->nextNode;
                    else if (curr == tail)
                       tail = prev;
                    temp = curr;
                    curr = curr->nextNode;
                    prev->nextNode = curr;
                    delete temp;
                    temp = nullptr;
                    nodeCount--;
                } else {
                    prev = curr;
                    curr = curr->nextNode;
                }
            }
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(nullptr);
        }
};

#endif
