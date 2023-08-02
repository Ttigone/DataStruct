#ifndef _DOUBLYLINKEDLIST__HPP_
#define _DOUBLYLINKEDLIST__HPP_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<class ElemType> 
class DLLNode {
    friend class DoublyLinkedList;
public:
    DLLNode() : prev(nullptr), next(nullptr) { }
    DLLNode(const ElemType &element, DLLNode *n = nullptr, DLLNode *p = nullptr) :
        info(element), prev(n), next(p) { }
public: 
    ElemType info;
    DLLNode *prev, *next;
};

namespace mydoublylist {         // 双向循环链表
template<class ElemType>
class DoublyLinkedList {
private:
    size_t m_length;
    DLLNode<ElemType> *head;
    
public:
/*
funtion: 默认构造函数
*/
    DoublyLinkedList() : m_length(0), head(new DLLNode<ElemType>) {
        head->next = head->prev = head;
    }

/*
funtion: 拷贝构造函数  初始化列表使用委托构造
*/
    DoublyLinkedList(const DoublyLinkedList<ElemType> &copy) :  DoublyLinkedList() {  // const 成员只能调用 const 成员函数
        head->next = head->prev = head;
        for (int i = 1; i <= copy.size(); ++i) {
            insert(i, copy.get_elem(i));
        }
    }

/*
funtion: 析构函数
*/
    ~DoublyLinkedList() {
        clear();
        delete head;
        head = nullptr;
    }
/*
funtion: 返回长度
parameter: none
return: 长度值
*/
    constexpr size_t size() const {
        return m_length;
    }

/*
funtion: 判断双向链表是否为空
parameter: none
return: true is empty, false is no emplty
*/
    constexpr bool empty() const {
        return m_length == 0;
    }

/*
funtion: 清除元素
parameter: none
return: none
*/
    void clear() {
        while(!empty()) {
            // way1 
            DLLNode<ElemType> *delete_point = head->next;
            head->next = delete_point->next;
            delete_point->next->prev = head;
            --m_length;
            delete delete_point;
            delete_point = nullptr;
            // way2
            // delete_element(1);
        }
    }

/*
funtion: 获取特定位置元素的指针
parameter: position-位置 从 0 开始
return: 指向该元素的指针-引用
*/
    DLLNode<ElemType> *get_elem_point(const int position) const {
        if (position < 0 || position > size()) {
            return nullptr;
        }
        auto traverse_point = head;         
        for (int i = 0; i < position; ++i) {
            traverse_point = traverse_point->next;
        }
        return traverse_point;
    }

/*
funtion: 获取特定位置元素
parameter: position-位置 从 1 开始
return: 元素
*/
    ElemType get_elem(const int position) const {
        return get_elem_point(position)->info;
    }
/*
funtion: 插入元素
parameter: position-位置, element-元素
return: none
*/
    bool insert(const int &position, const ElemType &element) {
        if(position < 1 || position > size() + 1) {
            return false;
        }
        DLLNode<ElemType> *traverse_point = get_elem_point(position - 1);  // 新节点的前一个节点
        if (!traverse_point) {
            return false;
        }
        DLLNode<ElemType> *new_point = new DLLNode<ElemType>;
        new_point->info = element;
        new_point->prev = traverse_point;              // 新节点指向前驱节点
        new_point->next = traverse_point->next;        // 新节点指向后一节点
        traverse_point->next->prev = new_point;        // 新节点的后一节点指向新节点
        traverse_point->next = new_point;              // 新节点的前一个节点指向新节点
        ++m_length;
        return true;
    }

/*
funtion: 删除元素
parameter: position-位置 element-保存删除元素
return: true is successful
*/
    bool delete_element(const int &position, ElemType &element) {
        if (position < 1 || position > size()) {
            return false;
        }
        DLLNode<ElemType> *delete_point = get_elem_point(position);  // 获取删除位置的指针
        element = delete_point->info;
        if (!delete_point) {
            return false;
        }
        delete_point->prev->next = delete_point->next;  // 删除节点的前一个节点指向删除节点的后一个节点
        delete_point->next->prev = delete_point->prev;  // 删除节点的后一个节点指向删除节点的前一个节点
        --m_length;
        delete delete_point;
        delete_point = nullptr;
    }

/*
funtion: 删除元素
parameter: position-位置 
return: 被删除元素的副本
*/
    ElemType delete_element(const int &position) {
        if (position < 1 || position > size()) {
            return false;
        }
        DLLNode<ElemType> *delete_point = get_elem_point(position);  // 获取删除位置的指针
        if (!delete_point) {
            return false;
        }
        ElemType keep_ = delete_point->info;
        delete_point->prev->next = delete_point->next;  // 删除节点的前一个节点指向删除节点的后一个节点
        delete_point->next->prev = delete_point->prev;  // 删除节点的后一个节点指向删除节点的前一个节点
        --m_length;
        delete delete_point;
        delete_point = nullptr;
        return keep_;

    }

/*
funtion: 遍历链表
parameter: none
return: none
*/
    bool traverse() {
        if (empty()) {
            return false;
        } else {
            DLLNode<ElemType> *traverse_point = head->next;
            while(traverse_point != head) {
                cout << traverse_point->info << " ";
                traverse_point = traverse_point->next;
            }
            return true;
        }
    }

/*
funtion: 在链表头部添加元素
parameter: 元素
return: true is successful
*/
    bool add_to_head(const ElemType &element) {
        // way1
        DLLNode<ElemType> *new_point = new (DLLNode<ElemType>);
        new_point->info = element;
        new_point->next = head->next;   // 新节点链接下一节点
        head->next->prev = new_point;   // 后继链接新节点
        new_point->prev = head;         // 新节点指向头结点 
        head->next = new_point;         // 头结点下一结点为新节点
        ++m_length;
        return true;
        // way2
        // return insert(1, element);
    }

/*
funtion: 在链表末尾添加元素
parameter: 元素
return: true is successful
*/
    bool add_to_tail(const ElemType &element) {
        // way1
        DLLNode<ElemType> *new_point = new (DLLNode<ElemType>);
        new_point->info = element;
        new_point->prev = head->prev;   // 新节点指向原最后一个元素
        head->prev->next = new_point;   // 原最后一个元素指向新最后一个元素
        new_point->next = head;       // 最后一个元素的 next 指向头结点
        head->prev = new_point;       // 头结点的 prev 指向最后一个元素
        ++m_length;
        return true; 
        //way2       
        // return insert(size() + 1, element);

    }

};

}

// template class DoublyLinkedList<ElemType> OK
#endif
