#ifndef _DEQUE__HPP_
#define _DEQUE__HPP_

#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

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
class Deque;

template<typename T>
struct DequeItem;

template<typename T>
void Maze_algorithm(Deque<T>& deque, 
                    std::vector<std::vector<int>>& map, 
                    int x1, int y1, int x2, int y2);

template<typename T>
void viewPath(const Deque<T>& deque);
}

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
    void traverse(void) const ;
    T getNext(int pos);
    T& getItem(int pos) const ;     // 根据下标获取对应的 Item
    const T& top() const ;

    void traverse_for_Maze(void) const ;


private:
    const T& at(int pos) const ;    // 下标
    T at(int pos) ;    // 下标

private: 
    struct DequeItem {        // 内部节点类型
    public:
        DequeItem(void);
        DequeItem(const T& val, DequeItem* next = nullptr);
    public:
        DequeItem& operator=(const DequeItem& rhs) = delete;
    public:
        T data;           // 队列在每个节点是 DequeItem    内部亦有两个域 传进来的 T 类型数据域，以及一个指针域
        DequeItem *next = nullptr;
    };

private:
    size_t m_length;
    DequeItem head;
    DequeItem tail;
    static int pos;

};

// 在类外部定义
template <typename T>
int Deque<T>::pos = 0;

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
Deque<T>::Deque() : m_length(0), head(DequeItem()), tail(DequeItem()) { }

template<typename T>
Deque<T>::Deque(const Deque &rhs) : Deque() {   // 委托构造
    for (int i = 0; i < rhs.size(); ++i) {
        push_back(rhs.at(i));
    }
}   

template <typename T>
Deque<T>::~Deque() {
    clear();
}

template<typename T>
void Deque<T>::clear() {  // NOTE  逐步释放队列中的元素
    erase(1, size() + 1);
}

template<typename T>
void Deque<T>::insert(int pos, const T& val) {
    size_t keepPosition = pos--;
    if (pos < 0 || pos > size()) {
        return;
    }
    auto traversePoint = head.next;
    if (pos == 0) {
        auto newPoint = new DequeItem(val, traversePoint);
        head.next = newPoint;
        tail.next = newPoint;        // tail_point 指向最后一个元素
    } else {
        while (--pos) {
            traversePoint = traversePoint->next;
        }
        auto newPoint = new DequeItem(val, traversePoint->next);
        traversePoint->next = newPoint;
        if (keepPosition == size() + 1) {
            tail.next = newPoint; 
        }
    }
    ++m_length;
}

template<typename T>
void Deque<T>::pop_back(void) {
    erase(size());
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
    if ((pos < 1 && pos > size()) || empty()) {
        return;
    }
    auto traversePoint = &head;
    while (--pos) {                  // 获取指向定位结点的前一个结点指针
        traversePoint = traversePoint->next;
    }
    auto deletePoint = traversePoint->next;
    traversePoint->next = deletePoint->next;
    delete deletePoint;
    deletePoint = nullptr;
    --m_length;
    if (empty()) {
        tail.next = nullptr;
    }
}

template<typename T>
void Deque<T>::erase(int first, int last) {  // 做闭右开
    size_t deleteCount = last - first;
    while (deleteCount--) {
        erase(first);
    }
}

template<typename T>
void Deque<T>::traverse(void) const {
    if (empty()) {
        return;
    }
    DequeItem *traversePoint = new DequeItem();
    traversePoint->next = head.next;
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

// template<typename T>
// T Deque<T>::top() {
//     return at(size() - 1);
// }

// template<typename T>
// T Deque<T>::at(int pos) {

// }

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