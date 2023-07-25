#ifndef _LINKLIST__HPP_
#define _LINKLIST__HPP_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<class ElemType>
struct Node {
    ElemType data;
    Node<ElemType> *next;
};

namespace mylist {
template<class ElemType>
class LinkList {
private:
    Node<ElemType> *head_point;  
    size_t m_length;

public:
    LinkList() : m_length(0), head_point(new Node<ElemType>) {head_point->next = nullptr;}
/*
funtion: 复制一个数组变为一个链表
pargamer: ElemType a[]:数组的指针 ;  n: 复制的个数
return: none
*/
    LinkList(ElemType target_[], int n) : m_length(0), head_point(new Node<ElemType>) {
        head_point->next = nullptr;
        for (int i = 0; i < n; ++i) {
            insert(i + 1, target_[i]);  // 可能会造成越界
        }
    }

/*
funtion: 拷贝构造函数
*/
    LinkList(const LinkList<ElemType> &copy) : m_length(copy.m_length), head_point(new Node<ElemType>){
        head_point->next = nullptr;
        for (int i = 1; i <= copy.m_length; ++i) {
            insert(i, copy.get_elem(i));
        }
    }

/*
funtion: 析构函数
*/
    ~LinkList() { delete[] head_point;}

public:
/*
funtion: 返回链表长度
parameter: none
return: 长度 length 
*/
    constexpr int size() const {
        return this->m_length;
    }

/*
funtion: 判断链表是否为空
parameter: none
return: true is empty, false is no empty
*/
    constexpr bool empty() const {
        if (!size()) {
            return true;
        } else {
            return false;
        }
    }

/*
funtion: 清空链表
parameter: none
return: none 
*/
    void clear() {
        // way 1
        /*
            while(m_length > 0) {
                delete_element(1);
            }
        */


        // way 2
            auto p = head_point->next;
            while (p) {
                auto delete_point = p;
                head_point->next = p->next;
                p = p->next;
                delete delete_point;
                delete_point = nullptr;
                --m_length;
            }
    }

/*
funtion: 根据位置获取元素, 通过 element 获得
parameter: 位置-position element-存储元素
return: 获取是否成功, 元素是否存在
*/
    bool get_elem(int position, ElemType &element) const {
        auto p = head_point->next;
        while (--position && p != NULL) {
            p = p->next;
        }
        if (p != NULL) {
            element = p->data;
            return "true";
        } else {
            throw "arg error";
            return false;
        }
    }
    
/*
funtion: 根据位置获取元素
parameter: 位置-position
return: 返回 数据域的引用 , 没有找到则抛出异常 
*/
    ElemType& get_elem(int position) const {
        auto p = head_point->next;
        while (--position && p != NULL) {
            p = p->next;
        }
        if (p != NULL) {
            return p->data;
        } else {
            throw "arg error";
        }
    }

/*
funtion: 将第 position 个元素设置为 element
parameter: position-位置 element-赋值的元素
return: true is successful, false is faild
*/
    bool set_elem(int position, const ElemType &element) {
        // way 1
        /*
            if (position < 1 ||  position > length()) {
                return false;
            }
            auto p = head_point->next;
            while (--position){
                p = p->next;   
            }
            p->data = e;
            return true;
        */
        // way 2
        // /*
            if (position < 1 || position > size()) {
                return false;
            }
            get_elem(position) = element;
            return true;
        // */
    }

/*
funtion: 根据元素定位其在链表中的位置
parameter: 传入元素
return: 找到的位置,若找不到，则返回 0 
*/
    int locate(ElemType x) {
        auto p = head_point->next;
        unsigned int i = 0;
        while (p != NULL) {
            ++i;
            if (p->data == x) {
                return i;
            } else {
                p = p->next;
            }
        }      
        return 0;
    }
    
/*
funtion: 向链表中插入元素
parameter: positon-插入的位置，e-插入的元素
return: true is successful false is faild 
*/
    bool insert(int position, const ElemType &e) {
        if (position < 1 || position > size() + 1) {
            return false;
        }
        auto p = head_point;
        while (--position) {
            p = p->next;
        }
        auto p_front = new (Node<ElemType>);
        p_front->data = e;  
        p_front->next = p->next;  
        p->next = p_front;
        ++m_length;
        return true;
    }

/*
funtion: 删除指定位置的元素
parameter: position-删除位置
return: true is successful, false is faild
*/
    bool delete_element(int position) {
        if (position < 1 || position > size()) {
            return false;
        }
        auto p = head_point;
        while (--position) {
            p = p->next;
        }
        decltype(p) Delete_point = p->next;
        p->next = Delete_point->next;
        delete Delete_point;
        Delete_point = nullptr;
        --m_length;
        return true;
    }

/*
funtion: 删除指定位置的元素, 并用 element 接受返回的值
parameter: position-删除位置 element-删除的元素
return: true is successful, false is faild
*/
    bool delete_element(int position, ElemType &element) {
        if (position < 1 || position > size()) {
            return false;
        }
        auto p = head_point;
        while (--position) {
            p = p->next;
        }
        decltype(p) Delete_point = p->next;
        element = Delete_point->data;
        p->next = Delete_point->next;
        delete Delete_point;
        Delete_point = nullptr;
        return true;
    }

/*
funtion: 打印链表
parameter: none
return: none
*/
    void traverse() {   
        auto p = head_point->next;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }


};

}

// template class LinkList<ELemType> OK
#endif