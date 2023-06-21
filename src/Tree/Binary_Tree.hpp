#ifndef _BINARY_TREE__HPP_
#define _BINARY_TREE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<class ElemType>
struct Tree_Node {
    ElemType data;
    Node *root;
    Node *left_child;
    Node *right_child;
};
namespace my_binary_tree {
    template<class ElemType>
    class Tree {

    /*
    funtion: 返回二叉树的根
    parameter: none
    return: 根节点
    */
        const Tree_Node<ElemType> * get_root() const {

        } 
    
    /*
    funtion: 判断二叉树是否为空
    parameter: none
    return: true is empty false is no empty
    */
        bool empty() const {

        }

    /*
    funtion: element 返回节点 cur 的元素值   
    parameter: cur-节点  element-存储
    return: true 代表存在该节点  false 则不存在
    */
        bool get_elem(const Tree_Node<ElemType> *cur, ElemType &element) const {
            
        }

    /*
    funtion: 将节点 cur 的元素值设置为 element   
    parameter: cur-节点 element-目标值
    return: true 代表存在该节点  false 则不存在
    */
        bool set_elem(Tree_Node<ElemType> *cur, const ElemType &element) {

        }

    /*
    funtion: 中序遍历二叉树，对每个节点访问 visit 函数 
    parameter:
    return: none
    */
        void in_order(void (*visit)(const ElemType &)) const {

        }

    /*
    funtion: 先序遍历二叉树，对每个节点访问 visit 函数 
    parameter:
    return: none
    */
        void pre_order(void (*visit)(const ElemType &)) const {

        }

    /*
    funtion: 后序遍历二叉树，对每个节点访问 visit 函数 
    parameter:
    return: none
    */
        void post_order(void (*visit)(const ElemType &)) const {

        }

    /*
    funtion: 层次遍历二叉树，对每个节点访问 visit 函数 
    parameter:
    return: none
    */
        void level_order(void (*visit)(const ElemType &)) const {

        }

    /*
    funtion: 求二叉树的节点个数
    parameter: none
    return: 节点个数
    */
        int node_count() const {

        }

    /*
    funtion: 返回节点 cur 的左孩子   
    parameter: 节点 cur 
    return: 左子树
    */
        const Tree_Node<ElemType> *left_child(const Tree_Node<ElemType> *cur) const {

        }

    /*
    funtion: 返回节点 cur 的右孩子   
    parameter: 节点 cur 
    return: 左子树
    */
        const Tree_Node<ElemType> *right_child(const Tree_Node<ElemType> *cur) const {

        }

    /*
    funtion: 返回节点 cur 的双亲节点   
    parameter: 节点 cur 
    return: 父亲节点 
    */
        const Tree_Node<ElemType> *parent(const Tree_Node<ElemType> *cur) const {

        }

    /*
    funtion: 插入 element 为 cur 的左孩子，若 cur 的左孩子非空，则 cur 原有左子树为 element 的左子树
    parameter: cur-节点 element-插入节点
    return: none
    */
        void insert_left_child(Tree_Node<ElemType> *cur, const ElemType &element) {

        }

    /*
    funtion: 插入 element 为 cur 的右孩子，若 cur 的右孩子非空，则 cur 原有右子树为 element 的右子树
    parameter: cur-节点 element-插入节点
    return: none
    */
        void insert_right_child(Tree_Node<ElemType> *cur, const ElemType &element) {

        }
    
    /*
    funtion: 删除节点的左子树
    parameter: cur-节点
    return: none
    */
        void delete_left_child(Tree_Node<ElemType> *cur) {

        }

    /*
    funtion: 删除节点的右子树
    parameter: cur-节点
    return: none
    */
        void delete_right_child(Tree_Node<ElemType> *cur) {

        }

    /*
    funtion: 返回树高   
    parameter: none
    return: 树高
    */
        int tree_height() const {

        }
    };

}

#endif