#ifndef _DEQUE__HPP_
#define _DEQUE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
struct DequeItem;
template <class T>
struct QNode {
    T data;
    QNode *next;
};

/**
 * @date 2023-08-15
 * 
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 * 
 * @brief 队列 
 */
namespace myqueue {

template<typename T>
class Deque {
public:
    Deque(void);
    Deque(const Deque& rhs);
    ~Deque(void);

public:
    inline bool empty(void) const noexcept { return m_length == 0; };
    inline size_t size(void) const noexcept { return m_length; };
    // inline DequeItem * begin();

public:
    void clear(void);
    void insert(int pos, const T& val);
    void pop_back(void);
    void pop_front(void);
    void push_back(const T& val);
    void push_front(const T& val);
    void erase(int pos);
    void erase(int first, int last);

    void traverse(void) const;

private: 
    struct DequeItem {
    public:
        DequeItem(void);
        DequeItem(const T& val, DequeItem* next = nullptr);
    public:
        DequeItem& operator=(const DequeItem& rhs) = delete;
    public:
        T data;
        DequeItem *next = nullptr;
    };

private:
    size_t m_length;
    QNode<T> *head_point;
    QNode<T> *tail_point;
    DequeItem head;
    DequeItem tail;


};

template<typename T>
Deque<T>::DequeItem::DequeItem(void) {
    data = T();
}

template<typename T>
Deque<T>::DequeItem::DequeItem(const T& val, DequeItem* next) {
    data = val;
    this->next = next;
}

template<typename T>
Deque<T>::Deque() : m_length(0), head(DequeItem(0)), tail(DequeItem(0)) { }

template<typename T>
Deque<T>::Deque(const Deque<T> &rhs) : Deque() {   // 委托构造
    // head_point->next = nullptr; 
    // QNode<T> *copy_point = (copy.head_point)->next;
    // if (!copy_point) {
    // } else {
    //     for (int i = 0; i < copy.m_length; ++i) {
    //         in_queue(copy_point->data);   // 会增加长度
    //         copy_point = copy_point->next;
    //     }  // 最后 copy_point 是 nullptr
    // }

}   

template <typename T>
Deque<T>::~Deque() {
    clear();
    delete head_point;
    head_point = tail_point = nullptr;
}

template<typename T>
void Deque<T>::clear() {  // NOTE  逐步释放队列中的元素
    QNode<T> *clear_point = new QNode<T>;
    clear_point = head_point->next;
    while (clear_point != nullptr) {   
        auto delete_point = clear_point;
        head_point->next = clear_point->next;
        clear_point = head_point->next;
        delete delete_point;   
        delete_point = nullptr;
    }
    m_length = 0;
    tail_point = head_point;
}

template<typename T>
void Deque<T>::insert(int pos, const T& val) {

}

template<typename T>
void Deque<T>::pop_back(void) {
    // if (empty()) {
    //     throw new std::logic_error("size error");
    // }
    // QNode<T> delete_point = new QNode<T>;
    // delete_point = head_point->next;   // 指向出队元素
    // element = delete_point->data;
    // head_point->next = delete_point->next;   // 头结点指向被删除节点的下一节点
    // delete delete_point;
    // delete_point = nullptr;
    // --m_length;   // 长度减 1
    // if (head_point->next == nullptr) {  // 当只有一个数据节点，且被删除时
    //     tail_point = head_point;
    // }
    // return true;
}

template<typename T>
void Deque<T>::pop_front(void) {

}

template<typename T>
void Deque<T>::push_back(const T& val) {
    // QNode<T> *new_point = new QNode<T>;
    // new_point->data = element;   // 存储数据域
    // new_point->next = tail_point->next;   // nullptr 的传递
    // tail_point->next = new_point;  // 链接新节点
    // tail_point = new_point;   // 尾指针指向最后一个元素
    // ++m_length;   // 长度 + 1
    // return true;
    // DequeItem *newPoint = new DequeItem(val, tail.next);
    // tail.next = newPoint;
    DequeItem *traversePoint = &head;
    
    DequeItem *newPoint = new DequeItem(val, traversePoint->next);
    // DequeItem *newPoint = new DequeItem(val, head.next);
    // head.next = newPoint;
    traversePoint->next = newPoint;
    ++m_length;
}

template<typename T>
void Deque<T>::push_front(const T& val) {
    DequeItem *newPoint = new DequeItem(val, head.next);
    head.next = newPoint;
    ++m_length;
}

template<typename T>
void Deque<T>::erase(int pos) {

}
template<typename T>
void Deque<T>::erase(int first, int last) {

}

template<typename T>
void Deque<T>::traverse(void) const {
    if (empty()) {
        return;
    }
    DequeItem *traversePoint = new DequeItem(0, head.next);
    traversePoint = traversePoint->next;
    cout << "head ";
    while (traversePoint != nullptr) {
        cout << traversePoint->data;
        if (traversePoint->next != nullptr) {
            cout << " ";
        }
        traversePoint = traversePoint->next;
    }
    cout << " tail";
}



// template<typename T >
// bool Deque<T>::get_head(T &element) const {
//     if (empty()) {
//         throw new std::logic_error("size error");
//     }
//     element = head_point->next->data;
//     return true;
// }

// template<typename T>
// QNode<T> *Deque<T>::begin() {
//     if (empty()) {
//         throw new std::logic_error("size error");
//     }
//     return head_point->next;
// }

}

// template class Deque<T> OK
#endif