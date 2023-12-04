#ifndef _STACK__HPP_
#define _STACK__HPP_

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * @date 2023-09-06
 * 
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 * 
 * @brief 顺序栈
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
class Stack;

template<typename T>
class StackItem;

template<typename T>
void viewQueenMap(const vector<vector<T>>& queenMap);

template<typename T>
bool isSafe(const vector<vector<T>>& queenMap, int row, int col);

template<typename T>
void Queen_Problem_With_Stack(int queens);

template<typename T>
void Queen_Problem_With_Recursion(vector<vector<T>>& queenMap, int queens, int row = 0);

template<typename T>
void showQueen(void); 
}

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

template<typename T>
void Queen_Problem_With_Staclk(int queens) {
    vector<vector<T>> queenMap;
    queenMap.insert(queenMap.begin(), queens, vector<T>(queens, 0));
    Stack<T> queenStack;                    
    int row = 0;                // 行遍历
    int col = 0;         // 每一行从第一列开始遍历
    while (row < queens) {
        bool placed = false;
        while (col < queens) {   // 2  0
            if (isSafe(queenMap, row, col)) {       // 判断 第 row + 1 行， col + 1 列是否可以皇后
                queenMap[row].at(col) = 1;       // 没有则在 该 row  + 1 行，col + 1 列放置皇后
                queenStack.push(col);               // 将列号入栈
                placed = true;                      // 放置成功
                break;                              // 退出循环
            }
            col++;
        }
        if (placed) {       // 如果放置成功，开始放置下一行的皇后
            row++;  
            col = 0;        
        } else {            // 没有放置成功
            if (queenStack.empty()) {         
                cout << "no";
                return;
            }
            int lastCol = queenStack.top();     // 获取最后的列号
            queenStack.pop();                   // 回退列号
            queenMap[--row].at(lastCol) = 0;   // 赋值为空
            if (lastCol == queens - 1) {
                col = queenStack.top() + 1;
                --row;
                queenMap[row].at(queenStack.top()) = 0;
                queenStack.pop();
            } else {
                col = lastCol + 1;
            }
        }
    }
    viewQueenMap(queenMap);
}


vector<vector<vector<int>>> result;
template<typename T>
void Queen_Problem_With_Recursion(vector<vector<T>>& queenMap, int queens, int row) {
    int trow = row;
    int tcol = 0;
    if (trow == queens) {
        result.push_back(queenMap);
        return;
    }
   while (tcol < queens) {
       if (isSafe(queenMap, trow, tcol)) {
           queenMap[trow].at(tcol) = 1;
           Queen_Problem_With_Recursion(queenMap, queens, trow + 1);
           queenMap[trow].at(tcol) = 0;
       }
       ++tcol;
   }
}

template<typename T>
void showQueen(void) {
    int num = 0;
    for (auto vec : result) {
        cout << "Group: " << ++num;
        for (int i = 0; i < vec.size(); ++i) {
            auto dis = find(vec[i].begin(), vec[i].end(), 1) - vec[i].begin();
            cout << '(' << i << ',' << dis << ')';
        }
        cout << endl;
    }
}


template<typename T>
void viewQueenMap(const vector<vector<T>>& queenMap) {
    for (auto i : queenMap) {
        for (auto j : i) {
            cout << j << " "; 
        }
        cout << endl;
    }
}

template<typename T>
bool isSafe(const vector<vector<T>>& queenMap, int row, int col) {
    for (int i = 0; i < queenMap.size(); ++i) {          // 判断当前列
        if (i == row) {        // 跳过
            continue;
        }
        if (queenMap[i].at(col) == 1) {
            return false;
        }
    }  
    for (int i = 0; i < queenMap.size(); ++i) {          // 判断当前行
        if (i == col) {
            continue;
        }
        if (queenMap[row].at(i) == 1) {
            return false;
        }
    }

    int n = 4;
    for (int t = 0, i, j; t < n; ++t) {
        switch (t) {
            case 0: {
                i = row, j = col;
                while (i >= 0 && j >= 0) {        // i = 0 说明在右上半区 j = 0 说明在左下半区
                    if (queenMap[i].at(j) == 1) {
                        return false;
                    }
                    --i, --j;     // 左上
                }
                break;
            }
            case 1: {
                i = row, j = col;
                while (i != queenMap.size() - 1 && j != queenMap.size() - 1) {
                    if (queenMap[i].at(j) == 1) {
                        return false;
                    }
                    ++i, ++j;           // 右下
                }
                break;
            }
            case 2: {
                i = row, j = col;             // 0, 0
                while (i >= 0 && j <= queenMap.size() -1) {
                    if (queenMap[i].at(j) == 1) {
                        return false;
                    }
                    --i, ++j;   // 右上
                }
                break;
            }
            case 3: {
                i = row, j = col;
                while (i <= queenMap.size() -1 && j >= 0) {
                    if (queenMap[i].at(j) == 1) {
                        return false;
                    }
                    ++i, --j;   // 左下
                }
                break; 
            }
        }
    }

    return true;
}

} // template class Stack<T> OK


#endif