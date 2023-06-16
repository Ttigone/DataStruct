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
template<class ElemType>
class LinkList {
public:
    LinkList() : m_length(0) {}
    ~LinkList() { delete[] first;}
private:
    Node<ElemType> *first;  
    size_t m_length;
public:
/*
funtion: 复制一个数组变为一个链表
pargamer: ElemType a[]:数组的指针 ;  n: 复制的个数
return: none
*/
    LinkList(ElemType target_[], int n) {
        auto p = first->next;
        for (int i = 0; i < n; ++i) {
            p->data = target_[i];
            p = p->next;
        }
    }

/*
funtion: 返回链表长度
parameter: none
return: 长度 length 
*/
    int Length() const {
        return this->length;
    }

/*
funtion: 判断链表是否为空
parameter: none
return: true is empty, false is no empty
*/
    bool Empty() const {
        if (!Length()) {
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
        auto p = first->next;
        while (p) {
            auto delete_point = p;
            first->next = p->next;
            delete delete_point;
            delete_point = nullptr;
        }
    }

/*
funtion: 根据位置获取元素, 通过 e 获得
parameter: 位置-position e-存储元素
return: 获取是否成功, 元素是否存在
*/
    bool GetElem(int position, ElemType &e) const {
        auto p = first->next;
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
funtion: 将第 position 个元素设置为 e
parameter: position-位置 e-赋值的元素
return: true is successful, false is faild
*/
    bool SetElem(int position, const ElemType &e) {
        if (position < 1 ||  position > Length()) {
            return false;
        }
        auto p = first->next;
        while (--position){
            p = p->next;   
        }
        p->data = e;
        return true;
    }

/*
funtion: 根据元素定位其在链表中的位置
parameter: 传入元素
return: 找到的位置,若找不到，则返回 0 
*/
    int Locate(ElemType x) {
        auto p = first->next;
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
    bool Insert(int position, const ElemType &e) {
        if (position < 1 || position > Length() + 1) {
            return false;
        }
        auto p = first;
        while (--position) {
            p = p->next;
        }
        decltype(p) p_front {nullptr};
        p_front->data = e;
        p_front->next = p->next;
        p->next = p_front;
        return true;
    }

/*
funtion: 删除指定位置的元素
parameter: position-删除位置
return: true is successful, false is faild
*/
    bool Delete(int position) {
        if (position < 1 || position > Length()) {
            return false;
        }
        auto p = first;
        while (--position) {
            p = p->next;
        }
        decltype(p) Delete_p = p->next;
        p->next = Delete_p->next;
        delete Delete_p;
        Delete_p = nullptr;
        return true;
    }

/*
funtion: 删除指定位置的元素, 并用 e 接受返回的值
parameter: position-删除位置 e-删除的元素
return: true is successful, false is faild
*/
    bool Delete(int position, ElemType &e) {
        if (position < 1 || position > Length()) {
            return false;
        }
        auto p = first;
        while (--position) {
            p = p->next;
        }
        decltype(p) Delete_p = p->next;
        p->next = Delete_p->next;
        delete Delete_p;
        Delete_p = nullptr;
        
        return true;
    }

/*
funtion: 打印链表
parameter: none
return: none
*/
    void Traverse() {
        auto p = first->next;
        while (p != NULL) {
            cout << p->data;
            p = p->next;
        }
    }
};

// template class LinkList<int>;

#endif

