#include <functional>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

template<typename dataType>
struct B_Node {
    dataType data;
    B_Node<dataType>* left;
    B_Node<dataType>* right;
    B_Node(dataType data): data(data), left(nullptr), right(nullptr) {}
};

template<typename dataType>
class sl_binary_tree {
    using nodeType = B_Node<dataType>;

    nodeType* root = nullptr;
    size_t size = 0;

    void inOrderTraversal(nodeType* root, std::function<void (const dataType&)> callBack) {
        if (root == nullptr) 
            return;

        inOrderTraversal(root->left, callBack);
        callBack(root->data);
        inOrderTraversal(root->right, callBack); 
    }

    void preOrderTraversal(nodeType* root, std::function<void (const dataType&)> callBack) {
        if (root == nullptr) 
            return;

        callBack(root->data);
        preOrderTraversal(root->left, callBack);
        preOrderTraversal(root->right, callBack); 
    }

    void postOrderTraversal(nodeType* root, std::function<void (const dataType&)> callBack) {
        if (root == nullptr)
            return;

        postOrderTraversal(root->left, callBack);
        postOrderTraversal(root->right, callBack); 
        callBack(root->data);
    }

    void deleteDeepestNode(nodeType* deepestNode) {
        std::queue<nodeType*> Q;
        nodeType* curr;
        Q.push(root);
        while (!Q.empty()) {
            curr = Q.front();
            Q.pop();
            if (curr == deepestNode) {
                curr = nullptr;
                delete deepestNode;
                return;
            }

            if (curr->right == deepestNode) {
                curr->right = nullptr;
                delete deepestNode;
                return;
            } else
                Q.push(curr->right);

            if (curr->left == deepestNode) {
                curr->left = nullptr;
                delete deepestNode;
                return;
            } else
                Q.push(curr->left);
        }
    }

    int getHeightOfTree(nodeType* root, int& height) {
        if (root == nullptr)
            return -1;

        int leftHeight = getHeightOfTree(root->left, height);
        int rightHeight = getHeightOfTree(root->right, height);

        int maxHeight = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;

        return maxHeight;
    }

    int countLeafs(nodeType* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;

        return countLeafs(root->left) + countLeafs(root->right);
    }

    public:
        sl_binary_tree() {}

        sl_binary_tree(const std::initializer_list<dataType>& li) {
            typename std::initializer_list<dataType>::iterator iter = li.begin();
            while (iter != li.end()) {
                insertValue(*iter);    
                iter++;
            }
        }

        sl_binary_tree(const size_t n, const dataType val) {
            for (int i=1; i <= n; i++)
                insertValue(val);
        }

        ~sl_binary_tree() {}

        // In order insertion
        void insertValue(const dataType& val) {
            size++;
            std::queue<nodeType*> Q;
            nodeType* newNode = new nodeType(val); 
            if (root == nullptr) {
                root = newNode;
                return;
            }
            Q.push(root);
            while (!Q.empty()) {
                nodeType* curr = Q.front();
                Q.pop();
                if (curr->left == nullptr) {
                    curr->left = newNode; 
                    return;
                } else if (curr->right == nullptr) {
                    curr->right = newNode;
                    return;
                } else {
                    Q.push(curr->left);
                    Q.push(curr->right);
                }
            }
        }

        void inOrderTraversal(std::function<void (const dataType&)> callBack) {
            inOrderTraversal(root, callBack);
        }

        void preOrderTraversal(std::function<void (const dataType&)> callBack) {
            preOrderTraversal(root, callBack);
        }

        void postOrderTraversal(std::function<void (const dataType&)> callBack) {
            postOrderTraversal(root, callBack);
        }

        bool contains(const dataType& val) {
            if (root == nullptr)
                return false;
            
            nodeType* curr;
            std::queue<nodeType*> Q;
            Q.push(root);
            while (!Q.empty()) {
                curr = Q.front();
                Q.pop();
                
                if (curr->data == val)
                    return true;
                
                if (curr->left)
                    Q.push(curr->left);

                if (curr->right)
                    Q.push(curr->right);
            }
            return false;
        }

        void removeValue(const dataType& key) {
            if (root == nullptr)
                return;

            if (root->left == nullptr && root->right == nullptr) {
                if (root->data == key) {
                    delete root;
                    root = nullptr;
                    return;
                }
            }

            nodeType* keyNode;
            nodeType* curr;
            std::queue<nodeType*> Q;
            Q.push(root);
            while (!Q.empty()) {
                curr = Q.front();
                Q.pop();

                if (curr->data == key)
                    keyNode = curr; if (curr->left) Q.push(curr->left);
                if (curr->right)
                    Q.push(curr->right);
            }

            if (keyNode != nullptr) {
                dataType temp = curr->data;
                keyNode->data = temp;
                deleteDeepestNode(curr);
            }
            size--;
        }

        dataType getMin() {
            if (root == nullptr) {
                std::cerr << "Error: tree is empty" << std::endl;
                exit(EXIT_FAILURE);
            }

            dataType min = root->data;
            nodeType* curr;
            std::queue<nodeType*> Q; 
            Q.push(root);
            while (!Q.empty()) {
               curr = Q.front();
               Q.pop();

               if (curr->data < min)
                   min = curr->data;

               if (curr->left)
                   Q.push(curr->left);

                if (curr->right)
                    Q.push(curr->right);
            }

            return min;
        }

        void clearTree(nodeType* root) {
            if (root == nullptr)
                return;

            clearTree(root->left);
            clearTree(root->right);

            delete root;
            root = nullptr;
        }

        void clearTree() {
            clearTree(root);
            root = nullptr;
            size = 0;
        }

        dataType getMax() {
            if (root == nullptr) {
                std::cerr << "Error: tree is empty" << std::endl;
                exit(EXIT_FAILURE);
            }

            dataType max = root->data;
            nodeType* curr;
            std::queue<nodeType*> Q; 
            Q.push(root);
            while (!Q.empty()) {
               curr = Q.front();
               Q.pop();

               if (curr->data > max)
                   max = curr->data;

               if (curr->left)
                   Q.push(curr->left);

                if (curr->right)
                    Q.push(curr->right);
            }
            return max;
        }

        int countLeafs() {
            return countLeafs(root);
        }

        int getHeightOfTree() {
            int  height = -1;
            return getHeightOfTree(root, height); 
        }

        bool empty() {
            return (size > 0) ? false : true;
        }

        int getSize() {
            return size;
        }

        void displayTree() {
            std::cout << "Tree: ";
            preOrderTraversal(root, [](const dataType& val){ std::cout << val << " ";});
            std::cout << std::endl;
        }
};

        /*
        int getNodeHeight(dataType val) {
            int height = -1;
            getNodeHeightFunc(root, val, height);

            return height;
        }


        int getNodeDepth(dataType val) {
            return getNodeDepthFunc(root, val);
        }

        bool isLeaf(dataType val) {
            std::queue<nodeType*> Q;
            nodeType* curr;
            if (root == nullptr)
                return false;
            Q.push(root);
            while (!Q.empty()) {
                curr = Q.front();
                Q.pop();

                if (curr->data == val) {
                    if (curr->left == nullptr && curr->right == nullptr)
                    return true;
                }

                if (curr->left)
                    Q.push(curr->left);

                if (curr->right)
                    Q.push(curr->right);
            }
            return false;
        }
        */
    /*
    int getNodeDepthFunc(nodeType* root, dataType val) {
        if (root == nullptr)
            return -1;

        int depth = -1;

        if ((root->data == val)
                || (depth = getNodeDepthFunc(root->left, val)) >= 0 
                || (depth = getNodeDepthFunc(root->right, val)) >= 0)
            return depth + 1;

        return depth;
    }
    

    int getNodeHeightFunc(nodeType* root, dataType val, int& height) {
        if (root == nullptr)
            return -1;

        int leftHeight = getNodeHeightFunc(root->left, val, height);
        int rightHeight = getNodeHeightFunc(root->right, val, height);

        int ans = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;

        if (root->data == val)
            height = ans;

        return ans;
    }
    */
