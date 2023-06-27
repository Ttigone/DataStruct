#ifndef _DEQUE__HPP_
#define _DEQUE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <class ElemType>
struct QNode {
    ElemType data;
    QNode *next;
};

namespace myqueue {

template <class ElemType>
class Deque {
private:
    QNode<ElemType> *head_point;
    QNode<ElemType> *tail_point;
    int m_length;

public:
/*
funtion: 默认构造函数
parameter: none
return: none
*/
    Deque() : m_length(0), 
              head_point(new QNode<ElemType>),
              tail_point(new QNode<ElemType>)
            { head_point->next = tail_point->next = nullptr; }
    
/*
funtion: 析构函数
parameter: none
return: none
*/
    ~Deque() {
        delete head_point;
        delete tail_point;
        head_point = tail_point = nullptr;
    }
    
public:
/*
funtion: 获取长度
parameter: none
return: 长度
*/
    int size() const {
        return m_length;
    }

/*
funtion: 设置当前长度
parameter: none
return: none
*/
    int& set_size() {
        return m_length;
    }

/*
funtion: 判断队列是否为空
parameter: none
return: true is empty false is no empty
*/
    bool empty() const {
        if (!m_length) {
            return true;
        } else {
            return false;
        }
    }

/*
funtion: 清空队列
parameter: none
return: none
*/
    void clear() {  // NOTE  逐步释放队列中的元素
        QNode<ElemType> *clear_point = new QNode<ElemType>;
        clear_point = head_point->next;
        while (clear_point != tail_point->next) {   
            auto delete_point = clear_point;
            head_point->next = clear_point->next;
            clear_point = head_point->next;
            delete delete_point;
            delete_point = nullptr;
        }
    }

/*
funtion: 遍历元素
parameter: none
return: none
*/
    void traverse() const {
        QNode<ElemType> *traverse_point = new QNode<ElemType>;       
        traverse_point = head_point->next;
        while (traverse_point != nullptr) {
            cout << "head ";
            cout << traverse_point->data;
            if (traverse_point != tail_point) {
                cout << " ";
            }
            traverse_point = traverse_point->next;
        }
        cout << "tail";
    }

/*
funtion: 在对头删除元素,并用存储值
parameter: element-存储值 
return: true is successful false is faild
*/
    bool out_queue(ElemType &element) {
        if (!size()) {
            throw new std::logic_error("size error");
        }
        QNode<ElemType> delete_point = new QNode<ElemType>;
        delete_point = head_point->next;
        element = delete_point->data;
        head_point->next = delete_point->next;
        delete delete_point;
        delete_point = nullptr;
        return true;
    }

/*
funtion: 在对头删除元素
parameter: none
return: true is successful false is faild
*/
    bool out_queue() {
        if (!size()) {
            throw new std::logic_error("size error");
        }
        QNode<ElemType> delete_point = new QNode<ElemType>;
        delete_point = head_point->next;
        head_point->next = delete_point->next;
        delete delete_point;
        delete_point = nullptr;
        return true;
    }

/*
funtion: 获取对头元素
parameter: element-存储元素
return: true is successful false is faild
*/
    bool get_head(ElemType &element) const {
        if (!size()) {
            throw new std::logic_error("size error");
        }
        element = head_point->next->data;
        return true;
    }

/*
funtion: 插入元素到队尾   左头右尾
parameter: element-待插入元素
return: true is successful false is faild 
*/
    bool in_queue(const ElemType &element){
        QNode<ElemType> *new_point = new QNode<ElemType>;
        new_point->data = element;
        if (size() == 0) {
            head_point->next = tail_point->next = new_point;
            new_point->next = nullptr;
            ++set_size();
        } else {
            new_point->next = (tail_point->next)->next; // BUG 入队
            (tail_point->next)->next = new_point;
            tail_point = new_point;
            ++set_size();
        }
        return true;
    }

    
};

}
#endif