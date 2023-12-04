#ifndef _DOUBLYLINKEDLIST__HPP_
#define _DOUBLYLINKEDLIST__HPP_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

<<<<<<< HEAD
=======

/**
 * @date 2023-06-15
 * 
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 * 
 * @brief 双向循环链表
 */

namespace mydoublylist {         

template<typename T>
class DoublyLinkedList;

template<typename T>
struct DLLItem;

template<typename T>
void erase_for_Joseph(DoublyLinkedList<T>& list, int pos);

template<typename T>
void Joseph_Problem(DoublyLinkedList<T>& list, int N, int k, int m);
>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea

/**
 * @date 2023-06-15
 * 
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 * 
 * @brief 双向循环链表
 */

<<<<<<< HEAD
namespace mydoublylist {         
template<typename T>
class DoublyLinkedList;

template<typename T>
struct DLLItem;

template<typename T>
void erase_for_Joseph(DoublyLinkedList<T>& list, int pos);

template<typename T>
void Joseph_Problem(DoublyLinkedList<T>& list, int N, int k, int m);
}

namespace mydoublylist {         
    
=======
>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea
template<typename T>
class DoublyLinkedList {
public:
    friend void erase_for_Joseph<>(DoublyLinkedList<T>& list, int pos);
    friend void Joseph_Problem<>(DoublyLinkedList<T>& list, int N, int k, int m);

public:
    DoublyLinkedList(void);
    DoublyLinkedList(const DoublyLinkedList& rhs);
    ~DoublyLinkedList(void);

private:
    struct DLLItem {
    public:
        DLLItem(void);
        DLLItem(const T& val, DLLItem* p = nullptr, DLLItem* n = nullptr);
    public:
        int getNumber(void) const noexcept { return number; };
        DLLItem& operator=(const DLLItem& rhs) = delete;
    public:
        T data;
        size_t freq = 0;
        size_t number = 0;
        DLLItem *prev = nullptr, *next = nullptr;
    };

private:
    size_t m_length;
    DLLItem head;

public:
    inline T& getElem(int pos);
    inline const T& getElem(int pos) const ;

public:
    void clear(void);
    size_t size(void) const noexcept { return m_length; }
    bool empty(void) const noexcept { return m_length == 0; }

    void insert(const int &pos, const T &val, int index = 0);
    void erase(int first, int last);
    void erase(int pos);
    void traverse(void);
    void push_front(const T& val);
    void push_back(const T& val, int index = 0);
    void locateNode(const T& val, int times = 1);
    void sort(void);
};

template<typename T>
DoublyLinkedList<T>::DLLItem::DLLItem(void) : prev(nullptr), next(nullptr) {
    data = T();
}

template<typename T>
DoublyLinkedList<T>::DLLItem::DLLItem(const T& val, DLLItem* p, DLLItem* n) : data(val), prev(p), next(n) { }


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : m_length(0), head(DLLItem(0)) {
    head.next = head.prev = &head;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& rhs) :  DoublyLinkedList() {  // const 成员只能调用 const 成员函数
    head.next = head.prev = &head;
    for (int i = 1; i <= rhs.size(); ++i) {
        insert(i, rhs.getElem(i));
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
T& DoublyLinkedList<T>::getElem(int pos) {
    auto traversePoint = head.next;
    while (traversePoint != &head && --pos) {
        traversePoint = traversePoint->next;
    }
    return traversePoint->data;
}

template<typename T>
const T& DoublyLinkedList<T>::getElem(int pos) const {
    auto traversePoint = head.next;
    while (traversePoint != &head && --pos) {
        traversePoint = traversePoint->next;
    }
    return traversePoint->data;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    erase(1, size() + 1);
}

template<typename T>
void DoublyLinkedList<T>::insert(const int& pos, const T& val, int index) {
    if(pos < 1 || pos > size() + 1) {
        return;
    }
    auto traversePoint = &head;
    for (int i = 1; i < pos; ++i) {
        traversePoint = traversePoint->next;
    }
    if (!traversePoint) {
        return;
    }
    DLLItem *newPoint = new DLLItem(val, traversePoint, traversePoint->next);
    newPoint->number = index;
    traversePoint->next->prev = newPoint;        // 新节点的后一节点指向新节点
    traversePoint->next = newPoint;              // 新节点的前一个节点指向新节点
    ++m_length;
}

template<typename T>
void DoublyLinkedList<T>::erase(int first, int last) { // 左闭右开
    for (int i = 0; i < last - first; ++i) {
        erase(first + i);
    }
}
template<typename T>
void DoublyLinkedList<T>::erase(int pos) {
    if (pos < 1 || pos > size()) {
        return;
    }
    auto traversePoint = &head;
    for (int i = 0; i < pos; ++i) {
        traversePoint = traversePoint->next;
    }
    if (!traversePoint) {
        return;
    }
    traversePoint->prev->next = traversePoint->next;  // 删除节点的前一个节点指向删除节点的后一个节点
    if (!traversePoint->next) {
        return;
    }
    traversePoint->next->prev = traversePoint->prev;
    --m_length;
    delete traversePoint;
    traversePoint = nullptr;
}

template<typename T>
void DoublyLinkedList<T>::traverse(void) {
    if (empty()) {
        return;
    }
    auto traversePoint = head.next;
    // while(traversePoint != &head) {
    while(traversePoint != &head) {
        if (traversePoint == nullptr) {
            return;
        }
        cout << traversePoint->data << " ";
        traversePoint = traversePoint->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& val) {
    insert(1, val);
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& val, int index) {
    insert(size() + 1, val, index);
}


template<typename T>
void DoublyLinkedList<T>::locateNode(const T& val, int times) {
    auto traversePoint = head.next;
    while (traversePoint != &head) {
        if (traversePoint->data == val) {
            (traversePoint->freq) += times;
        }
        traversePoint = traversePoint->next;
    }
    this->sort();
}


template<typename T>
void DoublyLinkedList<T>::sort(void) {   // 根据 freq 排序
    auto listHeader = &head;
    auto pt = listHeader->next->next;   // 指向首元结点下一结点的指针
    auto pt2 = pt;
    pt2 = nullptr;
    auto pre = listHeader;
    pre = nullptr;
    listHeader->next->next = &head;   // 当前链表只有一个首元结点，其指针域为循环的 &head
    while (pt != &head) {        // 只有一个数据时，不参加排序
        pt2 = pt->next;
        pre = listHeader;        // 每次获取弄好的新链表头结点
        while (pre->next != &head && pre->next->freq >= pt->freq) {
            pre = pre->next;
        }
        pt->next = pre->next;
        if (pre->next != &head) {
            pre->next->prev = pt;           // 前指针域连接
        }       
        pre->next = pt;
        pt->prev = pre;
        pt = pt2;
    }
    if (listHeader->next == listHeader->prev) {
        cout << "Y";
    }
    int t;
<<<<<<< HEAD
} // template class DoublyLinkedList<T> OK


=======
}

>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea
template<typename T>
void erase_for_Joseph(DoublyLinkedList<T>& list, int pos) {
    if (pos < 1 || pos > list.size()) {
        return;
    }
    auto traversePoint = &list.head;
    for (int i = 0; i < pos; ++i) {
        traversePoint = traversePoint->next;
    }
    if (!traversePoint) {
        return;
    }
    traversePoint->prev->next = traversePoint->next;  // 删除节点的前一个节点指向删除节点的后一个节点
    if (!traversePoint->next) {
        return;
    }
    traversePoint->next->prev = traversePoint->prev;
    cout << traversePoint->number << " ";
    --list.m_length;
    delete traversePoint;
    traversePoint = nullptr;
}

template<typename T>
void Joseph_Problem(DoublyLinkedList<T>& list, int N, int k, int m) {
    while (!list.empty()) {
        int currentSize = list.size();
        int eraseNum = (k - 1 + m) % currentSize--;  // 当删除到最后一个数字时，任何数对 1 取余均为 0
        if (currentSize == 0) {
            mydoublylist::erase_for_Joseph(list, 1);
            return;
        }
        if (eraseNum == 0) {
            mydoublylist::erase_for_Joseph(list, currentSize + 1);
            continue;
        }
        mydoublylist::erase_for_Joseph(list, eraseNum);
        k = eraseNum;
    }
<<<<<<< HEAD
=======


>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea
}


}

<<<<<<< HEAD
=======

// template class DoublyLinkedList<T> OK
>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea
#endif
