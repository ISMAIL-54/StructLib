#ifndef SL_HASHTABLE
#define SL_HASHTABLE
#include <functional>
#include <iostream>
#include <initializer_list>
#include <sstream>

template<typename keyType, typename valueType>
class sl_hashtable {
    size_t size = 0;
    size_t capacity = 20;

    struct ht_entry {
        keyType key;
        valueType value;
        ht_entry* nextEntry;
        ht_entry(const keyType& key, const valueType& value): key(key), value(value), nextEntry(nullptr) {};
    };

    ht_entry** hashtable;

    void allocateMemory() {
        hashtable = (ht_entry**) malloc(capacity * sizeof(ht_entry)); 
    }

    size_t getIndex(keyType key) {
        return std::hash<keyType>()(key) % capacity;
    }

    public:
        sl_hashtable() {
            allocateMemory();   
        }

        sl_hashtable(const std::initializer_list<std::pair<keyType, valueType>>& li) {
            allocateMemory();
            typename std::initializer_list<std::pair<keyType, valueType>>::iterator iter = li.begin();
            while (iter != li.end()) {
                insert(*iter);           
                iter++;
            }
        }

        void insert(const std::pair<keyType, valueType>& element) {
            size_t index = getIndex(element.first);
            if (hashtable[index] == nullptr) {
                hashtable[index] = new ht_entry(element.first, element.second);
            } else {
                ht_entry* node = hashtable[index]; 
                while (true) {
                    if (node->key == element.first) {
                        std::ostringstream err_msg;
                        err_msg << "Specified key is already exist in the table (key=" << element.first << ")";
                        throw std::invalid_argument(err_msg.str());
                    } else if (node->nextEntry != nullptr)
                        node = node->nextEntry;
                    else 
                        break;
                }
                node->nextEntry = new ht_entry(element.first, element.second);
            }
            size++;
        }

        void insert(const std::initializer_list<std::pair<keyType, valueType>> li) {
            typename std::initializer_list<std::pair<keyType, valueType>>::iterator iter = li.begin();
            while (iter != li.end()) {
                insert(*iter);
                iter++;
            }
        }

        const valueType& at(const keyType& key) {
            size_t index = getIndex(key);
            if (hashtable[index] != nullptr) {
                ht_entry* node = hashtable[index];
                while (node->key != key) {
                    node = node->nextEntry;
                }
                return node->value;
            }
            std::ostringstream err_msg;
            err_msg << "No element with the specified key (key=" << key << ")";
            throw std::invalid_argument(err_msg.str());
        }

        const valueType& operator[](const keyType& key) {
            return at(key);
        }
        
        void erase(const keyType& key) {
            size_t index = getIndex(key);
            if (hashtable[index] != nullptr) {
                size--;
                ht_entry* node = hashtable[index];
                if (node->nextEntry == nullptr) {
                    delete node;
                    hashtable[index] = nullptr;
                    return;
                }
                ht_entry* nextNode = node->nextEntry;
                while (nextNode->key != key) {
                    node = nextNode;
                    nextNode = nextNode->nextEntry;
                }
                delete nextNode;
                node->nextEntry = nullptr;
                return;
            }
            std::ostringstream err_msg;
            err_msg << "No element with the specified key (key="<< key << ")";
            throw std::invalid_argument(err_msg.str());
        }

        void clear() {
            for (int i=0; i < capacity; i++) {
                if (hashtable[i] != nullptr) {
                    ht_entry* node = hashtable[i];
                    ht_entry* temp = node->nextEntry;
                    while (node != nullptr) {
                        delete node;
                        node = temp;
                        temp = (temp) ? temp->nextEntry: temp;
                    }
                    hashtable[i] = nullptr;
                }
            }
            size = 0;
        }

        int count(const keyType& key) {
            size_t index = getIndex(key);
            if (hashtable[index] != nullptr) {
                ht_entry* node = hashtable[index];
                while (true) {
                    if (node->key == key)
                        return 1;
                    else if (node->nextEntry != nullptr)
                        node = node->nextEntry;
                    else
                        break;
                }
            }
            return 0;
        }

        size_t getSize() {
            return size;
        }

        bool empty() {
            return size ? false : true;
        }
};

#endif
