#ifndef _BINARY_TREE__HPP_
#define _BINARY_TREE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;


template<class ElemType>
struct TreeNode {
    ElemType data;
    TreeNode *lChild;
    TreeNode *rChild;
};
namespace mybinarytree {

template<class ElemType>
class Tree {

private:
    TreeNode<ElemType> *root;

private:
/*
function: 默认构造函数 - disable
*/
    Tree() : root(nullptr) {}

public:
/*
function: 有参构造函数 
*/
    Tree(char* str) : root(nullptr) {
        constexpr size_t strSize = sizeof(str);
        TreeNode<ElemType> *St[strSize] = {nullptr}; 
        TreeNode<ElemType> *temp = nullptr;
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
                    temp = new TreeNode<ElemType>();
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

/*
function: 有参构造函数
*/
    Tree(std::string str) : root(nullptr) {
        
    }


/*
function: 析构函数
*/
    ~Tree() {
        destroyTree(getRoot());
    }

public:
/*
function: 输出二叉树
*/
    void viewTree(TreeNode<ElemType>* node) {
        if (node) {
            cout << node->data;
            if (node->lChild || node->rChild) {
                cout << '(';
                viewTree(node->lChild);
                if (node->rChild) {
                    cout << ',';
                    viewTree(node->rChild);
                }
                cout << ')';
            }
        }
    }

/*
function: 输出叶子节点 left to right
parameter: node-根节点
return: none
*/
    void viewLeafL(TreeNode<ElemType>* node) {
        if (node) {
            if (node->lChild == nullptr && node->rChild == nullptr) {
                cout << node->data;
            }
            viewLeafL(node->lChild);
            viewLeafL(node->rChild);
        }
    }

/*
function: 输出叶子节点 right to left
parameter: node-根节点
return: none
*/
    void viewLeafH(TreeNode<ElemType>* node) {
        if (node) {
            if (node->lChild == nullptr && node->rChild == nullptr) {
                cout << node->data;
            }
            viewLeafH(node->rChild);
            viewLeafH(node->lChild);
        }
    }
    
/*
funtion: 返回二叉树的根
parameter: none
return: 根节点
*/
    constexpr TreeNode<ElemType>* getRoot() noexcept {
        return root;
    } 

/*
funtion: 判断二叉树是否为空
parameter: none
return: true is empty false is no empty
*/
    constexpr bool empty() {
        return root == nullptr;
    }

/*
function: 删除二叉树
parameter: root-根节点开始释放
return: none
*/
    void destroyTree(TreeNode<ElemType>* node) {
        if (node) {
            destroyTree(node->lChild);
            destroyTree(node->rChild);
            delete node;
        }
    }

/*
funtion: element 返回节点 node 的元素值   
parameter: cur-节点  element-存储
return: true 代表存在该节点  false 则不存在
*/
    bool getElem(const TreeNode<ElemType>* node, ElemType& element) const {
        if (!node) {
            return false;
        }
        element = node->data;
        return true;
    }

/*
function: 查找值为 element 的节点，并返回该节点
parameter: node-开始查找节点, element-查找元素
return: 节点指针类型
*/
    TreeNode<ElemType>* findNode(TreeNode<ElemType>* node, ElemType& element) {
        if (!node) {
            return nullptr;
        } else if (node->data == element) {
            return node;
        } else {
            TreeNode<ElemType>* temp = findNode(node->lChild, element);
            if (temp) {
                return temp;
            } else {
                return findNode(node->rChild, element);
            }
        }
    }

/*
funtion: 将节点 node 的元素值设置为 element   
parameter: cur-节点 element-目标值
return: true 代表存在该节点  false 则不存在
*/
    bool setElem(TreeNode<ElemType>* node, const ElemType& element) {
        if (!node) {
            return false;
        }
        findNode(node)->data = element;
        return true;
    }

/*
funtion: 中序遍历二叉树，对每个节点访问 visit 函数 
parameter:
return: none
*/
    void inOrder(TreeNode<ElemType>* node) {
        if (node) {
            inOrder(node->lChild);
            std::cout << node->data;
            inOrder(node->rChild);
        }
    }

/*
funtion: 先序遍历二叉树，对每个节点访问 visit 函数 
parameter:
return: none
*/
    void preOrder(TreeNode<ElemType>* node) {
        if (node) {
            std::cout << node->data;
            preOrder(node->lChild);
            preOrder(node->rChild);
        }
    }

/*
funtion: 后序遍历二叉树，对每个节点访问 visit 函数 
parameter:
return: none
*/
    void postOrder(TreeNode<ElemType>* node) {
        if (node) {
            postOrder(node->lChild);
            postOrder(node->rChild);
            cout << node->data;
        }
    }

/*
funtion: 层次遍历二叉树，对每个节点访问 visit 函数 
parameter:
return: none
*/
    void levelOrder(void (*visit)(const ElemType &)) const {

    }

/*
funtion: 求二叉树的节点个数
parameter: node-根节点
return: 节点个数
*/
    int nodeCount(TreeNode<ElemType>* node) {
        if (!node) {
            return 0;
        }
        return nodeCount(node->lChild) + nodeCount(node->rChild) + 1;
    }

/*
funtion: 返回节点 node 的左孩子   
parameter: node-节点
return: 左子树
*/
    const TreeNode<ElemType>* leftChild(const TreeNode<ElemType>* node) {
        return node->lChild;
    }

/*
funtion: 返回节点 node 的右孩子   
parameter: node-节点
return: 右子树
*/
    const TreeNode<ElemType>* rightChild(const TreeNode<ElemType>* node) {
        return node->rChild;
    }

/*
funtion: 返回节点 node 的父亲节点   
parameter: 节点 node
return: 父亲节点 
*/
    const TreeNode<ElemType> *parent(const TreeNode<ElemType>* node) {

    }

/*
funtion: 插入 element 为 cur 的左孩子，若 cur 的左孩子非空，则 cur 原有左子树为 element 的左子树
parameter: cur-节点 element-插入节点
return: none
*/
    void insertLeftChild(TreeNode<ElemType>* node, const ElemType& element) {

    }

/*
funtion: 插入 element 为 cur 的右孩子，若 cur 的右孩子非空，则 cur 原有右子树为 element 的右子树
parameter: cur-节点 element-插入节点
return: none
*/
    void insertRightChild(TreeNode<ElemType>* node, const ElemType& element) {

    }

/*
funtion: 删除节点的左子树
parameter: cur-节点
return: none
*/
    void deleteLeftChild(TreeNode<ElemType>* node) {

    }

/*
funtion: 删除节点的右子树
parameter: node-节点
return: none
*/
    void deleteRightChild(TreeNode<ElemType>* node) {

    }

/*
funtion: 返回树高   
parameter: node-节点 
return: 树高
*/
    int treeHeight(TreeNode<ElemType>* node) {
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

}

#endif