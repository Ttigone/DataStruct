#ifndef _LINKLIST__HPP_
#define _LINKLIST__HPP_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


template<typename T>
struct Node {
    T data;
    Node<T> *next;
};

/**
 * @brief 链表
 * 
 * @author C3H3_Ttigone
 * @date 2023-06-15
 */
namespace mylist {
template<class T>
class LinkList {
public:

    LinkList(void);
    LinkList(T target_[], int n);
    LinkList(const LinkList<T> &rhs);
    ~LinkList(void);

public:

    inline Node<T>* getHead(void) const { return head_point; }
    inline Node<T>* getTail(void) { return tail_point; }
    inline bool getElem(int position, T &element) const; 
    inline T& getElem(int position);
    inline const T& getElem(int position) const;
    inline bool empty(void) const { return m_length == 0; }
    inline int size(void) const { return this->m_length; }

    void clear(void); 
    int contain(T x);
    bool insert(int position, const T &element); 
    bool addToHead(const T &element);
    bool addToTail(const T &element);
    void remove(const T& val);
    bool deleteElem(int position);
    bool deleteElem(int position, T &element);
    void traverse() const;

    void setLength(size_t length) { m_length = length; }
    void setElem(int position, const T &element); 
    void setTail(Node<T> *tailPoint) { tail_point = tailPoint; }


private:
    // struct Node {
    //     T data;
    //     Node<T> *next;
    // };

    size_t m_length;
    Node<T> *head_point;
    Node<T> *tail_point;
};


template<typename T>
LinkList<T>::LinkList() : m_length(0), head_point(new Node<T>), tail_point(head_point)
{ head_point->next = nullptr; }

template<typename T>
LinkList<T>::LinkList(T target_[], int n) : m_length(0), head_point(new Node<T>) {
    head_point->next = nullptr;
    for (int i = 0; i < n; ++i) {
        insert(i + 1, target_[i]);  // 可能会造成越界
    }
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T> &rhs) : m_length(0), head_point(new Node<T>){
    head_point->next = nullptr;
    for (int i = 1; i <= rhs.m_length; ++i) {
        insert(i, rhs.getElem(i));
    }
}

template<typename T>
LinkList<T>::~LinkList() {
    clear();
    delete head_point;
    head_point = tail_point = nullptr;
}

template<typename T>
bool LinkList<T>::getElem(int position, T &element) const {
    auto traverse_point = head_point->next;
    while (--position && traverse_point != NULL) {
        traverse_point = traverse_point->next;
    }
    if (traverse_point != NULL) {
        element = traverse_point->data;
        return true;
    } else {
        throw "arg error";
    }
}

template<typename T>
const T& LinkList<T>::getElem(int position) const {
    auto p = head_point->next;
    while (--position && p != NULL) {
        p = p->next;
    }
    if (p != NULL) {
        return p->data;
    } else {
        throw "arg error";
    }
}

template<typename T>
T& LinkList<T>::getElem(int position) {
    auto p = head_point->next;
    while (--position && p != NULL) {
        p = p->next;
    }
    if (p != NULL) {
        return p->data;
    } else {
        throw "arg error";
    }
}

template<typename T>
void LinkList<T>::clear(void) {
    // way 1
    /*
        while(!isEmpty()) {
            delete_element(1);
        }
    */


    // way 2
    auto traverse_point = head_point->next;  // 从头部开始删除
    while (traverse_point) {
        auto delete_point = traverse_point;
        head_point->next = delete_point->next;
        traverse_point = traverse_point->next;  // 一旦 traverse_point 被赋值为 nullptr,说明正在删除最后一个节点
        if (traverse_point == nullptr) {
            tail_point = head_point;
        }
        delete delete_point;
        delete_point = nullptr;
        --m_length;
    }
}

template<typename T>
int LinkList<T>::contain(T x) {
    auto traverse_point = head_point->next;
    unsigned int i = 0;
    while (traverse_point != NULL) {
        ++i;
        if (traverse_point->data == x) {
            return i;
        } else {
            traverse_point = traverse_point->next;
        }
    }
    return 0;
}

template<typename T>
bool LinkList<T>::insert(int position, const T &element) {
    int keep_position = position;
    if (position < 1 || position > size() + 1) {
        return false;
    }
    auto traverse_point = head_point;
    while (--position) {
        traverse_point = traverse_point->next;
    }
    auto new_point = new (Node<T>);
    new_point->data = element;
    new_point->next = traverse_point->next;
    traverse_point->next = new_point;
    if (keep_position == size() + 1) {
        tail_point = new_point;        // tail_point 指向最后一个元素
    }
    ++m_length;
    return true;
}

template<typename T>
bool LinkList<T>::addToHead(const T &element) {
    Node<T> *new_point = new (Node<T>);
    new_point->data = element;
    new_point->next = head_point->next;
    head_point->next = new_point;
    ++m_length;
    return true;
}

template<typename T>
bool LinkList<T>::addToTail(const T &element) {
    Node<T> *new_point = new (Node<T>);
    new_point->data = element;
    new_point->next = tail_point->next; // nullptr 的传递
    tail_point->next = new_point;        // 链接新节点
    tail_point = new_point;       // tail_point 指向最后一个元素
    ++m_length;
    return true;
}

template<typename T>
void LinkList<T>::remove(const T& val) {


}

template<typename T>
bool LinkList<T>::deleteElem(int position) {
    if (position < 1 || position > size()) {
        return false;
    }
    int keep_position = position;
    auto traverse_point = head_point;
    while (--position) {
        traverse_point = traverse_point->next;
    }
    auto delete_point = traverse_point->next;
    traverse_point->next = delete_point->next;
    if (keep_position == size()) {  // 删除的是最后一个元素
        tail_point = traverse_point;   // tail_point 指向最后一个元素
    }
    delete delete_point;
    delete_point = nullptr;
    --m_length;
    return true;
}

// erase  
template<typename T>
bool LinkList<T>::deleteElem(int position, T &element) {
    if (position < 1 || position > size()) {
        return false;
    }
    int keep_position = position;
    auto traverse_point = head_point;
    while (--position) {
        traverse_point = traverse_point->next;
    }
    auto Delete_point = traverse_point->next;
    element = Delete_point->data;
    traverse_point->next = Delete_point->next;
    if (keep_position == size()) {
        tail_point = traverse_point;
    }
    delete Delete_point;
    Delete_point = nullptr;
    --m_length;
    return true;
}


template<typename T>
void LinkList<T>::traverse() const {
    auto traverse_point = head_point->next;
    while (traverse_point != NULL) {
        cout << traverse_point->data << " ";
        traverse_point = traverse_point->next;
    }
    cout << endl;
}


template<typename T>
void LinkList<T>::setElem(int position, const T &element) {
    // way 1
    /*
        if (position < 1 ||  position > length()) {
            return;
        }
        auto p = head_point->next;
        while (--position){
            p = p->next;
        }
        p->data = e;
        return;
    */
    // way 2
    // /*
    if (position < 1 || position > size()) {
        return;
    }
    getElem(position) = element;
    return;
}


/**
 * function: 合并链表
 * parameter: lhs, rhs - 合并链表  右合并到左
 * return: 合并后的链表 
 */ 
template<typename T>
LinkList<T> merge(LinkList<T> lhs, LinkList<T> rhs) {
    if (lhs.empty()) {
        return rhs;
    }
    if (rhs.empty()) {
        return lhs;
    }
    int tPos = 0, sizeOfLeft = lhs.size();
    while (++tPos <= rhs.size()) {
        lhs.insert(sizeOfLeft + tPos, rhs.getElem(tPos));
    }
    return lhs;
}

/**
 * function: 排序单链表
 * parametet: list-排序目标
 * return: none
 */ 
template<typename T>
const LinkList<T>& sort(const LinkList<T>& list) {
    // Node<T> *pt = head_point->next->next;
    auto listHeader = list.getHead();
    Node<T> *pt = listHeader->next->next;
    Node<T> *pt2 = nullptr;
    Node<T> *pre = nullptr;
    listHeader->next->next = nullptr;
    while (pt != nullptr) {        // 只有一个数据时，不参加排序
        pt2 = pt->next;  
        pre = listHeader;
        while (pre->next != nullptr && pre->next->data < pt->data) {
            pre = pre->next;
        }
        pt->next = pre->next;
        pre->next = pt;
        pt = pt2;
    }
    return list;
}

/**
 * function: 获取两个链表的交集
 * parameter: lhs,rhs 求交集的链表
 * return: 交集
 */
template<typename T>
LinkList<T> interSect(LinkList<T>& lhs, LinkList<T>& rhs) {
    LinkList<T> result;
    int iPos = 0, tPos = 0;
    while (++tPos <= lhs.size()) {
        T curValue = lhs.getElem(tPos);
        if (rhs.contain(curValue)) {
            result.insert(++iPos, curValue);
        }
    } 
    return result;

}

/**
 * function: 获取两个链表的差集
 * parameter: lhs,rhs 求差集的链表
 * return: 差集
 */ 
template<typename T>
LinkList<T> subs(LinkList<T> lhs, LinkList<T> rhs) {
    // lhs 的元素不能出现在 rhs 中
    int tPos = 0;
    while (++tPos <= lhs.size()) {
        if (rhs.contain(lhs.getElem(tPos))) {
            // 如果 rhs 中包含了 lhs 的元素，则删除 lhs 中的元素
            // 更新 tPos 指向的位置
            lhs.deleteElem(tPos--);  
        }
    }
    return lhs;
}


}

// template class LinkList<T> OK
#endif