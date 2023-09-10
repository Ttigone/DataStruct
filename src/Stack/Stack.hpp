#ifndef _STACK__HPP_
#define _STACK__HPP_

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


namespace mySeqStack { // 顺序栈
template<class ElemType>
class Stack {
private:
    int m_top;
    int m_base;
    int max_size;
    ElemType *data;
public:
/*
funtion: 有参构造函数
parameter: none
return:none
*/
    Stack(int init_size = 10) : m_top(0), m_base(0), max_size(init_size) {
        if (init_size <= 0) {
            throw new std::logic_error("size error");
        }
        data = new ElemType[max_size];
    }

/*
funtion: 拷贝构造函数
*/
    Stack(const Stack<ElemType> &copy) : m_top(0), m_base(0), max_size(copy.max_size) {
        for (int i = 0; i < copy.size(); ++i) {
            push(copy.data[i]);
        }
    }

/*
funtion: 析构函数
parameter: none
return: none
*/
    ~Stack() {
        delete [] data;
        data = nullptr;
    }

/*
funtion: 返回栈长度
parameter: none
return: 长度 length 
*/
    constexpr int size() const {
        return m_top - m_base;
    }

/*
funtion: 重新分配长度
parameter: none
return: none
*/
    void resize() noexcept {
        std::vector<ElemType> copy;
        for (int i = 0; i < size(); ++i) {
            copy.push_back(data[i]);
        }
        max_size = max_size + max_size / 2;
        data = new ElemType[max_size];
        for (int t = 0; t < size(); ++t) {
            data[t] = copy[t];
        }
    }

/*
funtion: 判断栈是否为空
parameter: none
return: true is empty false is no empty
*/
    constexpr bool empty() const {
        return m_base == m_top;
    }

/*
funtion: 清空栈
parameter: none
return: none
*/
    void clear() {
        m_top = m_base;
    }

/*
funtion: 入栈
parameter: element-入栈元素 
return: none 
*/
    void push(const ElemType element) {
        if (m_top - m_base == max_size) {
            // throw new std::logic_error("size full error");
            // 追加空间
            resize();
        } 
        data[m_top++] = element;
    }


/*
funtion: 出栈
parameter: element-存储出栈元素
return: true is successful false is faild
*/
    bool pop(const ElemType &element) {
        if (m_top == m_base) {
            return false;
        }
        element = data[m_top--];
        return true;
    }

/*
funtion: 出栈
parameter: none
return: true is successful false is faild 
*/
    ElemType pop() {
        if (empty()) {
            throw new std::logic_error("empty");
        }
        return data[--m_top];
    }

/*
funtion: 获取栈顶元素
parameter: none
return: 栈顶元素
*/
    ElemType getTop() {
        if (m_top > m_base) {
            int pos = m_top - 1;
            return data[pos];
        } else {
            throw new std::logic_error("get element error");
        }
    }

/*
funtion: 遍历栈
parameter: none
return: none
*/
    void traverse() {
        cout << "top ";
        for (int i = size() - 1; i >= 0; --i) {
            cout << data[i];
            if (i != 0) {
                cout << ", ";
            }
        }
        cout << " base";
    }


};

} // template class Stack<ElemType> OK

namespace myListStack {

template<typename ElemType>
struct StackNode {
    ElemType data;
    StackNode<ElemType> *next;
};
template<typename ElemType>
class Stack {
private: 
    StackNode<ElemType> *head; // 头结点
    size_t slength;
public:
/*
funtion: 默认构造函数
*/

    Stack() : head(new StackNode<ElemType>), slength(0) {
        head->next = nullptr;
    }

/*
funtion: 拷贝构造函数
*/
    Stack(const Stack<ElemType> &copy) : head(new StackNode<ElemType>), slength(0) {
        head->next = nullptr;
        auto clength = copy.length();
        for (int i = 0; i < clength; ++i) {
            push(copy.get(clength - i - 1));
        }
    }


/*
funtion: 析构函数
*/
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

/*
funtion: 判断是否为空
*/
    constexpr bool isEmpty() const {
        return head->next == nullptr;
    }

/*
funtion: 返回长度
*/
    constexpr size_t length() const {
        return slength;
    }

/*
funtion: 入栈
*/
    void push(const ElemType &element) {
        StackNode<ElemType> *newNode = new StackNode<ElemType>;
        newNode->data = element;
        newNode->next = head->next;
        head->next = newNode;
        ++slength;
    }

/*
funtion: 出栈
*/
    void pop(int i = 1) {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        auto deleteNode = head->next;
        head->next = deleteNode->next;
        delete deleteNode;
        deleteNode = nullptr;
        --slength;
    }

/*
funtion: 遍历栈
*/
    void traverse() const {
        auto traverseNode = head->next;
        while (traverseNode) {
            cout << traverseNode->data << " ";
            traverseNode = traverseNode->next;
        }
    }

/*
funtion: 获取特定位置的元素
*/
    ElemType get(int i = 0) const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        if (i >= length()) {
            cout << "y";
            throw std::runtime_error("Index out of range");
        }
        auto recordNode = head->next;
        while (i-- > 0) {
            recordNode = recordNode->next;
        }
        return recordNode->data;
    }



};

}


#endif