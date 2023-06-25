#ifndef _STACK__HPP_
#define _STACK__HPP_

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


namespace my_stack {
template<class ElemType>
class Stack {
private:
    ElemType *data;
    int m_top;
    int m_base;
    int max_size;
public:
/*
funtion: 有参构造函数
parameter: none
return:none
*/
    Stack(int init_size = 10) {
        if (init_size <= 0) {
            throw new std::logic_error("size error");
        }
        max_size = init_size;
        data = new ElemType[max_size];
        m_top = m_base = 0;
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
funtion: 返回链表长度
parameter: none
return: 长度 length 
*/
    int size() const {
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
    bool empty() const {
        if (!size()) {
            return true;
        } else {
            return false;
        }
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
    void push(const ElemType &element) {
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
    bool pop() {
        if (m_top == m_base) {
            return false;
        }
        --m_top;
        return true;
    }

/*
funtion: 获取栈顶元素
parameter: none
return: 栈顶元素
*/
    ElemType get_top() {
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

}

#endif