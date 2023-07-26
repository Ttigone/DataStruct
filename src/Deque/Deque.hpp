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
    int m_length;
    QNode<ElemType> *head_point;
    QNode<ElemType> *tail_point;

public:
/*
funtion: 默认构造函数
parameter: none
return: none
*/
    Deque() : m_length(0), 
              head_point(new QNode<ElemType>),
              tail_point(head_point)
            { head_point->next = nullptr; }
    
/*
funtion: 拷贝构造函数  // 深拷贝
*/
    Deque(const Deque<ElemType> &copy) : Deque() {   // 委托构造
        head_point->next = nullptr; 
        QNode<ElemType> *copy_point = (copy.head_point)->next;
        if (!copy_point) {
        } else {
            for (int i = 0; i < copy.m_length; ++i) {
                in_queue(copy_point->data);   // 会增加长度
                copy_point = copy_point->next;
            }  // 最后 copy_point 是 nullptr
        }
    }   
/*
funtion: 析构函数
parameter: none
return: none
*/
    ~Deque() {
        if (head_point != tail_point) {
            delete head_point;
            delete tail_point;
            head_point = tail_point = nullptr;
        } else {
            delete head_point;
            head_point = tail_point = nullptr;
        }
    }
    
public:
/*
funtion: 获取长度
parameter: none
return: 长度
*/
    constexpr int size() const {
        return m_length;
    }

/*
funtion: 判断队列是否为空
parameter: none
return: true is empty false is no empty
*/
    constexpr bool empty() const {
        return m_length == 0;
    }

/*
funtion: 清空队列
parameter: none
return: none
*/
    void clear() {  // NOTE  逐步释放队列中的元素
        QNode<ElemType> *clear_point = new QNode<ElemType>;
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

/*
funtion: 遍历元素
parameter: none
return: none
*/
    void traverse() const {
        if (empty()) {
            return;
        }
        QNode<ElemType> *traverse_point = new QNode<ElemType>;       
        traverse_point = head_point->next;
        cout << "head ";
        while (traverse_point != nullptr) {
            cout << traverse_point->data;
            if (traverse_point != tail_point) {
                cout << " ";
            }
            traverse_point = traverse_point->next;
        }
        cout << " tail";
    }

/*
funtion: 插入元素到队尾   左头右尾
parameter: element-待插入元素
return: true is successful false is faild 
*/
    bool in_queue(const ElemType element){
        QNode<ElemType> *new_point = new QNode<ElemType>;
        new_point->data = element;   // 存储数据域
        new_point->next = tail_point->next;   // nullptr 的传递
        tail_point->next = new_point;  // 链接新节点
        tail_point = new_point;   // 尾指针指向最后一个元素
        ++m_length;   // 长度 + 1
        return true;
    }


/*
funtion: 在队头删除元素,并存储值
parameter: element-存储值 
return: true is successful false is faild
*/
    bool out_queue(ElemType &element) {
        if (empty()) {
            throw new std::logic_error("size error");
        }
        QNode<ElemType> delete_point = new QNode<ElemType>;
        delete_point = head_point->next;   // 指向出队元素
        element = delete_point->data;
        head_point->next = delete_point->next;   // 头结点指向被删除节点的下一节点
        delete delete_point;
        delete_point = nullptr;
        --m_length;   // 长度减 1
        if (head_point->next == nullptr) {  // 当只有一个数据节点，且被删除时
            tail_point = head_point;
        }
        return true;
    }

/*
funtion: 在对头删除元素
parameter: none
return: true is successful false is faild
*/
    ElemType out_queue() {
        if (empty()) {
            throw new std::logic_error("size error");
        }
        QNode<ElemType> *delete_point = new QNode<ElemType>;
        delete_point = head_point->next;   // 指向出队元素
        auto keep_value = delete_point->data;
        head_point->next = delete_point->next;   // 头结点指向被删除节点的下一节点
        delete delete_point;
        delete_point = nullptr;
        --m_length;   // 长度减 1
        if (head_point->next == nullptr) {  // 当只有一个数据节点，且被删除时
            tail_point = head_point;
        }
        return keep_value;
    }

/*
funtion: 获取对头元素
parameter: element-存储元素
return: true is successful false is faild
*/
    bool get_head(ElemType &element) const {
        if (empty()) {
            throw new std::logic_error("size error");
        }
        element = head_point->next->data;
        return true;
    }


/*
funtion: 获取指向首元素的指针
parameter: none
return: 指针
*/
    QNode<ElemType> *begin() {
        if (empty()) {
            throw new std::logic_error("size error");
        }
        return head_point->next;
    }

};

}

// template class Deque<ElemType> OK
#endif