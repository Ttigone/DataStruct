#ifndef _STACK__HPP_
#define _STACK__HPP_

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


/**
 * @brief 顺序栈
 * 
 * @author C3H3_Ttigone
 * @date 2023-09-06
 */
namespace mySeqStack { 

template<typename T>
class Stack {
public:
    Stack(void);
    Stack(const Stack<T>& rhs);
    Stack& operator=(const Stack<T>& rhs);
    ~Stack(void);

public:

    inline T& top(void);
    inline const T& top(void) const;
    inline bool empty(void) const; 
    inline size_t size(void) const;

    void push(const T& val); 
    void pop(void); 
    void clear(); 
    void resize();
    void traverse() const; 

private:
    void copy(const Stack& rhs);  // 没有模板

private:
    int m_top;
    int m_base;
    int max_size;
    T *data;

};

template<typename T>
Stack<T>::Stack(void) {
    m_top = 0;
    m_base = 0;
    max_size = 10;
    data = new T[max_size];
}

template<typename T>
Stack<T>::Stack(const Stack<T>& rhs) : m_top(0), m_base(0), max_size(rhs.max_size) {
    for (int i = 0; i < rhs.size(); ++i) {
        push(rhs.data[i]);
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {

}

template<typename T>
Stack<T>::~Stack(void) {
    delete [] data;
    data = nullptr;
}


template<typename T>
T& Stack<T>::top() {
    if (m_top > m_base) {
        int pos = m_top - 1;
        return data[pos];
    } else {
        throw new std::logic_error("get element error");
    }
}

template<typename T>
const T& Stack<T>::top() const {
    if (m_top > m_base) {
        int pos = m_top - 1;
        return data[pos];
    } else {
        throw new std::logic_error("get element error");
    }
}


template<typename T>
bool Stack<T>::empty() const {
    return m_base == m_top;
}


template<typename T>
size_t Stack<T>::size() const {
    return m_top - m_base;
}

template<typename T>
void Stack<T>::push(const T& val) {
    if (m_top - m_base == max_size) {
        // throw new std::logic_error("size full error");
        // 追加空间
        resize();
    } 
    data[m_top++] = val;
}

template<typename T>
void Stack<T>::pop(void) {
    if (m_top == m_base) {
        return;
    }
    m_top--;
}

template<typename T>
void Stack<T>::clear() {
    m_top = m_base;
}

template<typename T>
void Stack<T>::resize() { 
    std::vector<T> copy;
    for (int i = 0; i < size(); ++i) {
        copy.push_back(data[i]);
    }
    max_size = max_size + max_size / 2;
    data = new T[max_size];
    for (int t = 0; t < size(); ++t) {
        data[t] = copy[t];
    }
}

template<typename T>
void Stack<T>::traverse() const {
    cout << "top ";
    for (int i = size() - 1; i >= 0; --i) {
        cout << data[i];
        if (i != 0) {
            cout << ", ";
        }
    }
    cout << " base";
}

} // template class Stack<T> OK



/**
 * @date 2023-09-06
 * 
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 * 
 * @brief 链栈
 */
namespace myListStack {

template<typename T>
class Stack {
public:
    Stack(void);
    Stack(const Stack<T> &rhs);
    ~Stack(void);

    inline T& top(void);
    inline const T& top(void) const;
    inline bool empty(void) const;
    inline size_t size(void) const;

    void push(const T &val);
    void pop(int i = 1);
    void clear();
    void traverse() const; 

private: 
    void copy(const Stack<T> &rhs);
    T get(int i = 0) const; 

private:
    struct StackItem {
    public:
        StackItem(void);
        StackItem(const T& val, StackItem* next = nullptr);
    public:
        StackItem& operator=(StackItem& rhs) = delete;  // 禁止拷贝
    public:
        StackItem *next = nullptr;
        T data;
    };

private: 
    StackItem head;
    size_t m_size;

};


template<typename T>
Stack<T>::StackItem::StackItem(void) {
    data = T();
}

template<typename T>
Stack<T>::StackItem::StackItem(const T& val, StackItem* next) {
    data = val;
    this->next = next;
}

template<typename T>
Stack<T>::Stack(void) : head(StackItem()), m_size(0) {        // head.next 指向新插入的结点

}

template<typename T>
Stack<T>::Stack(const Stack<T> &rhs) : head(StackItem()), m_size(0) {
    for (int i = 0; i < rhs.size(); ++i) {
        push(rhs.get(rhs.size() - i - 1));
    }
}

template<typename T>
Stack<T>::~Stack(void) {
    while (!empty()) {
        pop();
    }
}

template<typename T>
T& Stack<T>::top(void) {
    return head.next->data;
}

template<typename T>
const T& Stack<T>::top(void) const {
    return head.next->data;
}

template<typename T>
bool Stack<T>::empty(void) const { 
    return !size(); 
}

template<typename T>
size_t Stack<T>::size() const {
    return m_size; 
}

template<typename T>
void Stack<T>::push(const T& val) {
    StackItem *newNode = new StackItem(val, head.next);
    head.next = newNode;
    ++m_size;
}

template<typename T>
void Stack<T>::pop(int i) {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    auto deleteNode = head.next;
    head.next = deleteNode->next;         
    delete deleteNode;
    deleteNode = nullptr;
    --m_size;
}
    
template<typename T>
void Stack<T>::clear() {

}

template<typename T>
void Stack<T>::traverse() const {
    auto traverseNode = head.next;
    while (traverseNode) {
        cout << traverseNode->data << " ";
        traverseNode = traverseNode->next;
    }
}

template<typename T>   
T Stack<T>::get(int i) const {
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    if (i >= size()) {
        cout << "y";
        throw std::runtime_error("Index out of range");
    }
    auto recordNode = head.next;
    while (i-- > 0) {
        recordNode = recordNode->next;
    }
    return recordNode->data;
}

} // template class Stack<T> OK


#endif