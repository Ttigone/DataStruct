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
    inline static int& getPos(void) noexcept { return pos; };    // 获取下标

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
    T getNext(int pos);
    T& getItem(int pos) const;     // 根据下标获取对应的 Item

    void traverse_for_Maze(void) const;

private:
    T& at(int pos) const;    // 下标

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
    DequeItem *deletePoint = (&head)->next;
    if (deletePoint == nullptr) {
        tail.next = nullptr;
        return;
    } 
    head->next = deletePoint->next;             
    delete deletePoint;
    deletePoint = nullptr;
    --m_length;
    // erase(1);
}


template<typename T>
void Deque<T>::push_back(const T& val) {
    if (tail.next == nullptr) {             // 第一个位置
        insert(1, val);
        return;
    }
    DequeItem *newPoint = new DequeItem(val, (tail.next)->next);
    (tail.next)->next = newPoint;
    tail.next = newPoint;
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



template<typename T>
T Deque<T>::getNext(int pos) {        // 并未真正出队列
    DequeItem *traversePoint = head.next;
    while (pos--) {
        traversePoint = traversePoint->next;
    }
    return traversePoint->data;
}

template<typename T>
T& Deque<T>::getItem(int pos) const {    // 根据下标获取对应的 Item
    return at(pos);
}


template<typename T>
void Deque<T>::traverse_for_Maze(void) const {
    if (empty()) {
        return;
    }
    DequeItem *traversePoint = new DequeItem();
    traversePoint->next = head.next;
    traversePoint = traversePoint->next;
    int i = 0;
    while (traversePoint != nullptr) {
        cout << traversePoint->data;
        ++i;
        if (traversePoint->next != nullptr) {
            cout << " ";
        }
        if (i == 5) {
            cout << endl;
            i = 0;
        }
        traversePoint = traversePoint->next;
    }
}

template<typename T>
T& Deque<T>::at(int pos) const {   // 下标
    auto traversePoint = head.next;
    while (pos--) {
        traversePoint = traversePoint->next;
    }
    return traversePoint->data;

} // template class Deque<T> OK


template<typename T>
void Maze_algorithm(Deque<T>& deque, 
                    std::vector<std::vector<int>>& map, 
                    int x1, int y1, int x2, int y2) 
{
    if (map[x1].at(y1) == 1 || map[x2].at(y2) == 1) {
        cout << "Start Point or End Point is wall";
        return;
    }
    T item(x1, y1, -1);
    deque.push_back(item);
    int recordPos = 0;
    map[x1].at(y1) = -1;  // 移除遍历
    while (!deque.empty()) {    // 队列非空
        item = deque.getNext(Deque<T>::getPos());
        if (item.i == x2 && item.j == y2) {
            viewPath(deque);
            return;
        }
        for (int t = 0, tx, ty; t < 4; ++t) {
            switch (t) {
                case 0: tx = item.i - 1, ty = item.j; break;       // up
                case 1: tx = item.i, ty = item.j + 1; break;       // right
                case 2: tx = item.i + 1, ty = item.j; break;       // down
                case 3: tx = item.i, ty = item.j - 1; break;       // left
            }
            if (map[tx].at(ty) == 0) {                           // 可以走
                deque.push_back(T(tx, ty, Deque<T>::getPos()));
                map[tx].at(ty) = -1;
            }
        }
        ++Deque<T>::getPos();
    }
    deque.~Deque();
    return;
}

template<typename T>
void viewPath(const Deque<T>& deque) {
    Deque<T> path;
    for (int i = deque.getPos(); i != -1; i = (deque.getItem(i)).pre) {
        path.push_front(deque.getItem(i));
    }    
    path.traverse_for_Maze();
}

}

#endif