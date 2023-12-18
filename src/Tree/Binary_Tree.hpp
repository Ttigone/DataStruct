#ifndef _BINARY_TREE__HPP_
#define _BINARY_TREE__HPP_

#include <iostream>
#include <string>
#include <queue>
#include "../Stack/Stack.hpp"

/**
 * @date 2023-11
 *
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 *
 * @brief 二叉树
 */

using std::cin;
using std::cout;
using std::endl;
using std::string;


template<class T>
struct TreeNode {
    T data;
    TreeNode *lChild;
    TreeNode *rChild;
};
namespace mybinarytree {

template<class T>
class Tree {
public:
    Tree(void);
    Tree(char* str);
    Tree(std::string str);
    Tree(const std::string pre, const std::string in, size_t n);
    ~Tree(void);

public:
    TreeNode<T>* createTreePI(const std::string pre, const std::string in, size_t n);
    TreeNode<T>* createTreeIP(const std::string in, const std::string post, size_t n);  
    void viewBeginNode(TreeNode<T>* node) const ;
    void preOrderBeginNode(TreeNode<T>* node) ;
    void inOrderBeginNode(TreeNode<T>* node) ;
    void postOrderBeginNode(TreeNode<T>* node) ;

    void viewLeafL(TreeNode<T>* node) const ;
    void viewLeafH(TreeNode<T>* node) const ;
    void viewTree() const ;
    const string& inOrder();
    const string& inOrderNoRecursion();
    const string& preOrder();
    const string& preOrderNoRecursion();
    const string& postOrder();
    const string& postOrderNoRecursion();
    const string& levelOrder();

    constexpr bool empty();
    constexpr TreeNode<T>* getRoot() const ;
    void destroyTree(TreeNode<T>* node);
    bool getElem(const TreeNode<T>* node, T& element) const ;
    TreeNode<T>* findNode(TreeNode<T>* node, T& element);
    bool setElem(TreeNode<T>* node, const T& element);

    int nodeCount(TreeNode<T>* node);
    const TreeNode<T>* leftChild(const TreeNode<T>* node);
    const TreeNode<T>* rightChild(const TreeNode<T>* node);
    const TreeNode<T>* parent(const TreeNode<T>* node);
    void insertLeftChild(TreeNode<T>* node, const T& element);
    void insertRightChild(TreeNode<T>* node, const T& element);
    void deleteLeftChild(TreeNode<T>* node);
    void deleteRightChild(TreeNode<T>* node);
    int treeHeight(TreeNode<T>* node);

private:
    TreeNode<T> *root;
    string inStr;
    string preStr;
    string postStr;
    string levelStr;

    myListStack::Stack<TreeNode<T> *> u_stack;
    queue<TreeNode<T> *> u_queue;

};

template<typename T>
Tree<T>::Tree(void) : root(nullptr), inStr(), preStr(), postStr() {

}

template<typename T>
Tree<T>::Tree(char* str) : Tree() {
    size_t strSize = sizeof(str);
    TreeNode<T> *St[strSize] = {nullptr}; 
    TreeNode<T> *temp = nullptr;
    int top = -1, k = 0, j = 0;
    char ch = str[j];
    while (ch != '\0') {
        switch (ch) {
            case '(': {
                top++;
                St[top] = temp;
                k = 1;
                break;
            }
            case ')': {
                top--;
                break;
            }
            case ',': {
                k =  2;
                break;
            }
            default: {
                temp = new TreeNode<T>();
                temp->data = ch;
                // cout << ch << endl; 
                temp->lChild = temp->rChild = nullptr;
                if (!root) {
                    root = temp;
                } else {
                    switch (k) {
                        case 1: {
                            St[top]->lChild = temp; break;
                        }
                        case 2: {
                            St[top]->rChild = temp; break;
                        }
                    }
                }
            }
        }
        ++j;
        ch = str[j];
    }
}


template<typename T>
Tree<T>::Tree(std::string str) : Tree() {
    
}


template<typename T>
Tree<T>::Tree(const std::string pre, const std::string in, size_t n) : Tree() {
    root = createTreePI(pre, in, n);
}


template<typename T>
Tree<T>::~Tree(void) {
    destroyTree(getRoot());
}

template<typename T>
TreeNode<T>* Tree<T>::createTreePI(
        const std::string pre, 
        const std::string in, 
        size_t n                ) 
{
    if (n <= 0) {
        return nullptr;
    }
    TreeNode<T>* b = new TreeNode<T>;
    b->data = pre.at(0);  // 根节点数据域
    auto it = in.begin();
    for (; it != in.end(); ++it) {
        if (*it == pre.at(0)) {
            break;
        }
    }
    int r = it - in.begin();
    b->lChild = createTreePI(pre.substr(1, pre.size() - 1), in, r);
    b->rChild = createTreePI(pre.substr(r + 1, pre.size() - (r + 1)), in.substr(r + 1, in.size() - (r + 1)), n - r - 1);
    return  b;
}

template <typename T>
TreeNode<T>* Tree<T>::createTreeIP(
    const std::string in,            // 中序
    const std::string post,          // 后序
    size_t n                    )  
{
    if (n <= 0) {
        return nullptr;
    }
    auto inSize = in.size();
    auto postSize = post.size();
    TreeNode<T> *b = new TreeNode<T>;
    b->data = post.at(postSize - 1);                 // 存储根节点
    auto it = in.begin();
    for (; it != in.end(); ++it) {
        if (*it == b->data) {
            break;
        }
    }
    int r = it - in.begin();            // r 为根节点在中序的下标
    b->lChild = createTreeIP(in.substr(0, r), post.substr(0, r), r);
    b->rChild = createTreeIP(in.substr(r + 1, inSize - (r + 1)), post.substr(r , postSize - (r + 1)), n - (r + 1));
    return b;
}        

template <typename T>
void Tree<T>::viewBeginNode(TreeNode<T>* node) const {
    if (node) {
        cout << node->data;
        if (node->lChild || node->rChild) {
            cout << '(';
            viewBeginNode(node->lChild);
            if (node->rChild) {
                cout << ',';
                viewBeginNode(node->rChild);
            }
            cout << ')';
        }
    }
}

template<typename T>
void Tree<T>::viewTree() const {
    viewBeginNode(getRoot());
}

template <typename T>
void Tree<T>::viewLeafL(TreeNode<T>* node) const {
    if (node) {
        if (node->lChild == nullptr && node->rChild == nullptr) {
            cout << node->data;
        }
        viewLeafL(node->lChild);
        viewLeafL(node->rChild);
    }
}

template<typename T>
void Tree<T>::viewLeafH(TreeNode<T>* node) const {
    if (node) {
        if (node->lChild == nullptr && node->rChild == nullptr) {
            cout << node->data;
        }
        viewLeafH(node->rChild);
        viewLeafH(node->lChild);
    }
}

template<typename T>
constexpr TreeNode<T>* Tree<T>::getRoot() const {
    return root;
} 

template<typename T>
constexpr bool Tree<T>::empty() {
    return root == nullptr;
}

template<typename T>
void Tree<T>::destroyTree(TreeNode<T>* node) {
    if (node) {
        destroyTree(node->lChild);
        destroyTree(node->rChild);
        delete node;
    }
}

template<typename T>
bool Tree<T>::getElem(const TreeNode<T>* node, T& element) const {
    if (!node) {
        return false;
    }
    element = node->data;
    return true;
}

template<typename T>
TreeNode<T>* Tree<T>::findNode(TreeNode<T>* node, T& element) {
    if (!node) {
        return nullptr;
    } else if (node->data == element) {
        return node;
    } else {
        TreeNode<T>* temp = findNode(node->lChild, element);
        if (temp) {
            return temp;
        } else {
            return findNode(node->rChild, element);
        }
    }
}

template<typename T>
bool Tree<T>::setElem(TreeNode<T>* node, const T& element) {
    if (!node) {
        return false;
    }
    findNode(node)->data = element;
    return true;
}

template<typename T>
const string& Tree<T>::inOrder() {
    inOrderBeginNode(getRoot());
    return inStr;
}

template<typename T>
const string& Tree<T>::inOrderNoRecursion() {
    inStr.clear();
    TreeNode<T>* node = root;
    while (!u_stack.empty() || node != nullptr) {
        while (node != nullptr) {           // 持续将左子树入栈
            u_stack.push(node);
            node = node->lChild;
        }
        if (!u_stack.empty()) {             // 寻找右子树中的左子树
            auto top = u_stack.top();
            u_stack.pop();
            inStr.push_back(top->data);
            node = top->rChild;
        }
    }
    return inStr;
}


template<typename T>
void Tree<T>::inOrderBeginNode(TreeNode<T>* node) {
    if (node) {
        inOrderBeginNode(node->lChild);
        inStr.push_back(node->data);
        inOrderBeginNode(node->rChild);
    }
}

template<typename T>
void Tree<T>::preOrderBeginNode(TreeNode<T>* node) {
    if (node) {
        preStr.push_back(node->data);
        preOrderBeginNode(node->lChild);
        preOrderBeginNode(node->rChild);
    }
}

template<typename T>
void Tree<T>::postOrderBeginNode(TreeNode<T>* node) {
    if (node) {
        postOrderBeginNode(node->lChild);
        postOrderBeginNode(node->rChild);
        postStr.push_back(node->data);
    }
}

template<typename T>
const string& Tree<T>::preOrder() {
    preOrderBeginNode(getRoot());
    return preStr;
}

template<typename T>
const string& Tree<T>::preOrderNoRecursion() {
    preStr.clear();
    TreeNode<T>* node = root;
    if (node != nullptr) {
        u_stack.push(node);
        while (!u_stack.empty()) {
            auto top = u_stack.top();
            u_stack.pop();
            preStr.push_back(top->data);
            if (top->rChild != nullptr) {
                u_stack.push(top->rChild);
            }
            if (top->lChild != nullptr) {
                u_stack.push(top->lChild);
            }
        }
        preStr.push_back('\n');
    }
    return preStr;
}

template<typename T>
const string& Tree<T>::postOrder() {
    postOrderBeginNode(getRoot());
    return postStr;
}

template<typename T>
const string& Tree<T>::postOrderNoRecursion() {
    postStr.clear();
    TreeNode<T>* tem = nullptr;
    bool flags = false;
    TreeNode<T>* node = root;
    do {
        while (node != nullptr) {
            u_stack.push(node);
            node = node->lChild;
        }
        tem = nullptr;
        flags = true;
        while (!u_stack.empty() && flags) {
            node = u_stack.top();
            // if (node->rChild == nullptr) {

            // }
            if (node->rChild == tem) {
                postStr.push_back(node->data);
                u_stack.pop();
                tem = node;
            } else {
                node = node->rChild;
                flags = false;
            }
        }
    } while (!u_stack.empty());

    return postStr;
}

template<typename T>
const string& Tree<T>::levelOrder() {
    u_queue.push(root);
    TreeNode<T> *node = nullptr;
    while (!u_queue.empty()) {
        node = u_queue.front();
        u_queue.pop();
        levelStr.push_back(node->data);
        if (node->lChild != nullptr) {
            u_queue.push(node->lChild);
        }
        if (node->rChild != nullptr) {
            u_queue.push(node->rChild);
        }
    }
    return levelStr;
}

template<typename T>
int Tree<T>::nodeCount(TreeNode<T>* node) {
    if (!node) {
        return 0;
    }
    return nodeCount(node->lChild) + nodeCount(node->rChild) + 1;
}

template<typename T>
const TreeNode<T>* leftChild(const TreeNode<T>* node) {
    return node->lChild;
}

template<typename T>
const TreeNode<T>* Tree<T>::rightChild(const TreeNode<T>* node) {
    return node->rChild;
}

template<typename T>
const TreeNode<T> *Tree<T>::parent(const TreeNode<T>* node) {

}

template<typename T>
void Tree<T>::insertLeftChild(TreeNode<T>* node, const T& element) {

}

template<typename T>
void insertRightChild(TreeNode<T>* node, const T& element) {

}

template<typename T>
void Tree<T>::deleteLeftChild(TreeNode<T>* node) {

}

template<typename T>
void Tree<T>::deleteRightChild(TreeNode<T>* node) {

}

template<typename T>
int Tree<T>::treeHeight(TreeNode<T>* node) {
    int leftChildH = 0, rightChildH = 0;
    if (!node) {
        return 0;
    } else {
        leftChildH = treeHeight(node->lChild);
        rightChildH = treeHeight(node->rChild);
        return 1 + std::max(leftChildH, rightChildH);
    }
    return 0;
}

};


#endif




namespace b {
// #ifndef _BINARY_TREE__HPP_
// #define _BINARY_TREE__HPP_

// #include <iostream>
// #include <string>

// using std::cin;
// using std::cout;
// using std::endl;


// namespace mybinarytree {
// template<typename T>
// class Tree;

// template<typename T>
// struct TreeItem;

// template<typename T>
// using s = Tree<T>::TreeItem;
// }


// namespace mybinarytree {
// template<typename T>
// class Tree {


// public:
//     Tree(void);
//     Tree(char *s);
//     Tree(std::string str);
//     Tree(const std::string pre, const std::string in, size_t n);
//     ~Tree(void);

// public:
//     // inline TreeItem<T>* getRoot() noexcept { return &root; }
//     typename s* getRoot() noexcept { return &root; }
//     inline bool empty() { return root == nullptr; }

// public:
//     TreeItem<T>* createTreePI(const std::string pre, const std::string in, size_t n);
//     TreeItem<T>* createTeeIP(const std::string in, const std::string pre, size_t n);
//     // void viewTree(TreeItem<T>* node = &root);
//     void viewTree(TreeItem<T>* node);
//     void viewLeafL(TreeItem<T>* node);
//     void viewLeafH(TreeItem<T>* node);
//     void destroyTree(TreeItem<T>* node);

//     bool getElem(const TreeItem<T>* node, T& val) const ;
//     bool setElem(TreeItem<T>* node, const T& val);

// private:
//     struct TreeItem {
//     public:
//         TreeItem(void);
//         TreeItem(T data, TreeItem* l, TreeItem* r);
//         ~TreeItem(void);

//     public:
//         TreeItem& operator=(const TreeItem& rhs) = delete;
//     public:
//         T data;
//         TreeItem *lChild = nullptr;
//         TreeItem *rChild = nullptr;
//     };

// private:
//     TreeItem root;
// };

// template<typename T>
// Tree<T>::TreeItem::TreeItem(void) {
//     data = T();
// }

// template<typename T>
// Tree<T>::TreeItem::TreeItem(T data, TreeItem* l, TreeItem* r) : TreeItem() {
//     this->data = data;
//     lChild = l;
//     rChild = r;
// }

// template<typename T>
// Tree<T>::TreeItem::~TreeItem(void) {

// }

// template<typename T>
// Tree<T>::Tree(void) : root(TreeItem()) {}

// template<typename T>
// Tree<T>::Tree(char* str) : Tree() {
//     constexpr size_t strSize = sizeof(str);
// //    TreeNode<T> *St[strSize] = {nullptr};
// //    TreeNode<T> *temp = nullptr;
//     TreeItem *St[strSize] = {nullptr};
//     TreeItem *temp = nullptr;
//     int top = -1, k = 0, j = 0;
//     char ch = str[j];
//     while (ch != '\0') {
//         switch (ch) {
//             case '(': {
//                 top++;
//                 St[top] = temp;
//                 k = 1;
//                 break;
//             }
//             case ')': {
//                 top--;
//                 break;
//             }
//             case ',': {
//                 k =  2;
//                 break;
//             }
//             default: {
// //                temp = new TreeNode<T>();
//                 temp = new TreeItem();
//                 temp->data = ch;
//                 // cout << ch << endl;
//                 temp->lChild = temp->rChild = nullptr;
//                 // if (!root) {
//                 //     root = temp;
//                 if (!(&root)) {
//                     // root = TreeItem(ch);
//                     // root = *temp;
//                 } else {
//                     switch (k) {
//                         case 1: {
//                             St[top]->lChild = temp; break;
//                         }
//                         case 2: {
//                             St[top]->rChild = temp; break;
//                         }
//                     }
//                 }
//             }
//         }
//         ++j;
//         ch = str[j];
//     }
// }

// template<typename T>
// Tree<T>::Tree(std::string str) : Tree() {

// }

// template<typename T>
// Tree<T>::Tree(const std::string pre, const std::string in, size_t n) : Tree() {
//     root = createTreePI(pre, in, n);
// }

// template<typename T>
// Tree<T>::~Tree() {
// //     destroyTree(getRoot());
// }

// template<typename T>
// TreeItem<T>* createTreePI(
//         const std::string pre,
//         const std::string in,
//         size_t n                )
// {
//     if (n <= 0) {
//         return nullptr;
//     }
//     TreeItem<T>* b = new TreeItem<T>(pre.at(0));
// //    b->data = pre.at(0);  // 根节点数据域
//     auto it = in.begin();
//     for (; it != in.end(); ++it) {
//         if (*it == pre.at(0)) {
//             break;
//         }
//     }
//     int r = it - in.begin();
//     b->lChild = createTreePI<T>(pre.substr(1, pre.size() - 1), in, r);
//     b->rChild = createTreePI<T>(pre.substr(r + 1, pre.size() - (r + 1)), in.substr(r + 1, in.size() - (r + 1)), n - r - 1);
//     return  b;
// }

// /*
// function: 中序后序构造二叉树
// */
// template<typename T>
// TreeItem<T>* createTreeIP(
//         const std::string in,            // 中序
//         const std::string post,          // 后序
//         size_t n                    )
// {
//     if (n <= 0) {
//         return nullptr;
//     }
//     auto inSize = in.size();
//     auto postSize = post.size();
//     TreeItem<T> *b = new TreeItem<T>();
//     b->data = post.at(postSize - 1);                 // 存储根节点
//     auto it = in.begin();
//     for (; it != in.end(); ++it) {
//         if (*it == b->data) {
//             break;
//         }
//     }
//     int r = it - in.begin();            // r 为根节点在中序的下标
//     b->lChild = createTreeIP<T>(in.substr(0, r), post.substr(0, r), r);
//     b->rChild = createTreeIP<T>(in.substr(r + 1, inSize - (r + 1)), post.substr(r , postSize - (r + 1)), n - (r + 1));
//     return b;
// }

// template<typename T>
// void viewTree(TreeItem<T>* node) {
//     if (node) {
//         cout << node->data;
//         if (node->lChild || node->rChild) {
//             cout << '(';
//             viewTree(node->lChild);
//             if (node->rChild) {
//                 cout << ',';
//                 viewTree(node->rChild);
//             }
//             cout << ')';
//         }
//     }
// }

// template<typename T>
// void viewLeafL(TreeItem<T>* node) {
//     if (node) {
//         if (node->lChild == nullptr && node->rChild == nullptr) {
//             cout << node->data;
//         }
//         viewLeafL(node->lChild);
//         viewLeafL(node->rChild);
//     }
// }

// /*
// function: 输出叶子节点 right to left
// parameter: node-根节点
// return: none
// */
// template<typename T>
// void viewLeafH(TreeItem<T>* node) {
//     if (node) {
//         if (node->lChild == nullptr && node->rChild == nullptr) {
//             cout << node->data;
//         }
//         viewLeafH(node->rChild);
//         viewLeafH(node->lChild);
//     }
// }

// /*
// function: 删除二叉树
// parameter: root-根节点开始释放
// return: none
// */
// template<typename T>
// void destroyTree(TreeItem<T>* node) {
//     if (node) {
//         destroyTree(node->lChild);
//         destroyTree(node->rChild);
//         delete node;
//     }
// }


// //template<typename T>
// //bool getElem(const TreeItem<T>* node, T& val) const {
// //    if (!node) {
// //        return false;
// //    }
// //    val = node->data;
// //    return true;
// //}

// /*
// function: 查找值为 element 的节点，并返回该节点
// parameter: node-开始查找节点, element-查找元素
// return: 节点指针类型
// */
// template<typename T>
// TreeItem<T>* findNode(TreeItem<T>* node, T& val) {
//     if (!node) {
//         return nullptr;
//     } else if (node->data == val) {
//         return node;
//     } else {
//         TreeItem<T>* temp = findNode(node->lChild, val);
//         if (temp) {
//             return temp;
//         } else {
//             return findNode(node->rChild, val);
//         }
//     }
// }

// /*
// funtion: 将节点 node 的元素值设置为 element
// parameter: cur-节点 element-目标值
// return: true 代表存在该节点  false 则不存在
// */
// // template<typename T>
// // bool Tree<T>::setElem(TreeItem* node, const T& val) {
// //     if (!node) {
// //         return false;
// //     }
// //     findNode(node)->data = val;
// //     return true;
// // }

// /*
// funtion: 中序遍历二叉树，对每个节点访问 visit 函数
// parameter:
// return: none
// */
// template<typename T>
// void inOrder(TreeItem<T>* node) {
//     if (node) {
//         inOrder(node->lChild);
//         std::cout << node->data;
//         inOrder(node->rChild);
//     }
// }

// /*
// funtion: 先序遍历二叉树，对每个节点访问 visit 函数
// parameter:
// return: none
// */
// template<typename T>
// void preOrder(TreeItem<T>* node) {
//     if (node) {
//         std::cout << node->data;
//         preOrder(node->lChild);
//         preOrder(node->rChild);
//     }
// }

// /*
// funtion: 后序遍历二叉树，对每个节点访问 visit 函数
// parameter:
// return: none
// */
// template<typename T>
// void postOrder(TreeItem<T>* node) {
//     if (node) {
//         postOrder(node->lChild);
//         postOrder(node->rChild);
//         cout << node->data;
//     }
// }

// /*
// funtion: 层次遍历二叉树，对每个节点访问 visit 函数
// parameter:
// return: none
// */
// // template<typename T>
// // void levelOrder(void (*visit)(const T &)) const {

// // }

// /*
// funtion: 求二叉树的节点个数
// parameter: node-根节点
// return: 节点个数
// */
// template<typename T>
// int nodeCount(TreeItem<T>* node) {
//     if (!node) {
//         return 0;
//     }
//     return nodeCount(node->lChild) + nodeCount(node->rChild) + 1;
// }

// /*
// funtion: 返回节点 node 的左孩子
// parameter: node-节点
// return: 左子树
// */
// template<typename T>
// const TreeItem<T>* leftChild(const TreeItem<T>* node) {
//     return node->lChild;
// }

// /*
// funtion: 返回节点 node 的右孩子
// parameter: node-节点
// return: 右子树
// */
// template<typename T>
// const TreeItem<T>* rightChild(const TreeItem<T>* node) {
//     return node->rChild;
// }

// /*
// funtion: 返回节点 node 的父亲节点
// parameter: 节点 node
// return: 父亲节点
// */
// template<typename T>
// const TreeItem<T>* parent(const TreeItem<T>* node) {

// }

// /*
// funtion: 插入 element 为 cur 的左孩子，若 cur 的左孩子非空，则 cur 原有左子树为 element 的左子树
// parameter: cur-节点 element-插入节点
// return: none
// */
// template<typename T>
// void insertLeftChild(TreeItem<T>* node, const T& val) {

// }

// /*
// funtion: 插入 element 为 cur 的右孩子，若 cur 的右孩子非空，则 cur 原有右子树为 element 的右子树
// parameter: cur-节点 element-插入节点
// return: none
// */
// template<typename T>
// void insertRightChild(TreeItem<T>* node, const T& val) {

// }

// /*
// funtion: 删除节点的左子树
// parameter: cur-节点
// return: none
// */
// template<typename T>
// void deleteLeftChild(TreeItem<T>* node) {

// }

// /*
// funtion: 删除节点的右子树
// parameter: node-节点
// return: none
// */
// template<typename T>
// void deleteRightChild(TreeItem<T>* node) {

// }

// /*
// funtion: 返回树高
// parameter: node-节点
// return: 树高
// */
// template<typename T>
// int treeHeight(TreeItem<T>* node) {
//     int leftChildH = 0, rightChildH = 0;
//     if (!node) {
//         return 0;
//     } else {
//         leftChildH = treeHeight(node->lChild);
//         rightChildH = treeHeight(node->rChild);
//         return 1 + std::max(leftChildH, rightChildH);
//     }
//     return 0;
// }


// }

// #endif

}