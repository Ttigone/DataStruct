//#ifndef _LINKLIST__HPP_
//#define _LINKLIST__HPP_
//
//#include <iostream>
//
//using std::cout;
//using std::cin;
//using std::endl;
//
//template<class ElemType>
//struct Node {
//    ElemType data;
//    Node<ElemType> *next;
//};
//
//namespace mylist {
//template<class ElemType>
//class LinkList {
//private:
//    size_t m_length;
//    Node<ElemType> *head_point;
//    Node<ElemType> *tail_point;
//
///*
//funtion: 默认构造函数
//*/
//public:
//    LinkList() : m_length(0), head_point(new Node<ElemType>), tail_point(head_point)
//     { head_point->next = nullptr; }
//
///*
//funtion: 复制一个数组变为一个链表
//pargamer: ElemType a[]:数组的指针 ;  n: 复制的个数
//return: none
//*/
//    LinkList(ElemType target_[], int n) : m_length(0), head_point(new Node<ElemType>) {
//        head_point->next = nullptr;
//        for (int i = 0; i < n; ++i) {
//            insert(i + 1, target_[i]);  // 可能会造成越界
//        }
//    }
//
///*
//funtion: 拷贝构造函数
//*/
//    LinkList(const LinkList<ElemType> &copy) : m_length(copy.m_length), head_point(new Node<ElemType>){
//        head_point->next = nullptr;
//        for (int i = 1; i <= copy.m_length; ++i) {
//            insert(i, copy.get_elem(i));
//        }
//    }
//
///*
//funtion: 析构函数
//*/
//    ~LinkList() {
//        clear();
//        delete head_point;
//        head_point = tail_point = nullptr;
//    }
//
//public:
///*
//funtion: 返回链表长度
//parameter: none
//return: 长度 length
//*/
//    constexpr int size() const {
//        return this->m_length;
//    }
//
///*
//funtion: 判断链表是否为空
//parameter: none
//return: true is empty, false is no empty
//*/
//    constexpr bool empty() const {
//        return m_length == 0;
//    }
//
///*
//funtion: 清空链表
//parameter: none
//return: none
//*/
//    void clear() {
//        // way 1
//        /*
//            while(!empty()) {
//                delete_element(1);
//            }
//        */
//
//
//        // way 2
//            auto traverse_point = head_point->next;  // 从头部开始删除
//            while (traverse_point) {
//                auto delete_point = traverse_point;
//                head_point->next = delete_point->next;
//                traverse_point = traverse_point->next;  // 一旦 traverse_point 被赋值为 nullptr,说明正在删除最后一个节点
//                if (traverse_point == nullptr) {
//                    tail_point = head_point;
//                }
//                delete delete_point;
//                delete_point = nullptr;
//                --m_length;
//            }
//    }
//
///*
//funtion: 根据位置获取元素, 通过 element 获得
//parameter: 位置-position element-存储元素
//return: 获取是否成功, 元素是否存在
//*/
//    bool get_elem(int position, ElemType &element) const {
//        auto traverse_point = head_point->next;
//        while (--position && traverse_point != NULL) {
//            traverse_point = traverse_point->next;
//        }
//        if (traverse_point != NULL) {
//            element = traverse_point->data;
//            return true;
//        } else {
//            throw "arg error";
//        }
//    }
//
///*
//funtion: 根据位置获取元素
//parameter: 位置-position
//return: 返回 数据域的引用 , 没有找到则抛出异常
//*/
//    ElemType& get_elem(int position) const {
//        auto p = head_point->next;
//        while (--position && p != NULL) {
//            p = p->next;
//        }
//        if (p != NULL) {
//            return p->data;
//        } else {
//            throw "arg error";
//        }
//    }
//
///*
//funtion: 将第 position 个元素设置为 element
//parameter: position-位置 element-赋值的元素
//return: true is successful, false is faild
//*/
//    bool set_elem(int position, const ElemType &element) {
//        // way 1
//        /*
//            if (position < 1 ||  position > length()) {
//                return false;
//            }
//            auto p = head_point->next;
//            while (--position){
//                p = p->next;
//            }
//            p->data = e;
//            return true;
//        */
//        // way 2
//        // /*
//            if (position < 1 || position > size()) {
//                return false;
//            }
//            get_elem(position) = element;
//            return true;
//        // */
//    }
//
///*
//funtion: 根据元素定位其在链表中的位置
//parameter: 传入元素
//return: 找到的位置,若找不到，则返回 0
//*/
//    int locate(ElemType x) {
//        auto traverse_point = head_point->next;
//        unsigned int i = 0;
//        while (traverse_point != NULL) {
//            ++i;
//            if (traverse_point->data == x) {
//                return i;
//            } else {
//                traverse_point = traverse_point->next;
//            }
//        }
//        return 0;
//    }
//
///*
//funtion: 向链表中插入元素
//parameter: positon-插入的位置，e-插入的元素
//return: true is successful false is faild
//*/
//    bool insert(int position, const ElemType &element) {
//        int keep_position = position;
//        if (position < 1 || position > size() + 1) {
//            return false;
//        }
//        auto traverse_point = head_point;
//        while (--position) {
//            traverse_point = traverse_point->next;
//        }
//        auto new_point = new (Node<ElemType>);
//        new_point->data = element;
//        new_point->next = traverse_point->next;
//        traverse_point->next = new_point;
//        if (keep_position == size() + 1) {
//            tail_point = new_point;        // tail_point 指向最后一个元素
//        }
//        ++m_length;
//        return true;
//    }
//
///*
//funtion: 将元素插入在头部
//parameter: element-元素
//return: bool 值
//*/
//    bool add_to_head(const ElemType &element) {
//        Node<ElemType> *new_point = new (Node<ElemType>);
//        new_point->data = element;
//        new_point->next = head_point->next;
//        head_point->next = new_point;
//        ++m_length;
//        return true;
//    }
//
///*
//funtion: 将元素插入在尾部
//parameter: element-元素
//return: bool 值
//*/
//    bool add_to_tail(const ElemType &element) {
//        Node<ElemType> *new_point = new (Node<ElemType>);
//        new_point->data = element;
//        new_point->next = tail_point->next; // nullptr 的传递
//        tail_point->next = new_point;        // 链接新节点
//        tail_point = new_point;       // tail_point 指向最后一个元素
//        ++m_length;
//        return true;
//    }
//
///*
//funtion: 删除指定位置的元素
//parameter: position-删除位置
//return: true is successful, false is faild
//*/
//    bool delete_element(int position) {
//        if (position < 1 || position > size()) {
//            return false;
//        }
//        int keep_position = position;
//        auto traverse_point = head_point;
//        while (--position) {
//            traverse_point = traverse_point->next;
//        }
//        auto delete_point = traverse_point->next;
//        traverse_point->next = delete_point->next;
//        if (keep_position == size()) {  // 删除的是最后一个元素
//            tail_point = traverse_point;   // tail_point 指向最后一个元素
//        }
//        delete delete_point;
//        delete_point = nullptr;
//        --m_length;
//        return true;
//    }
//
///*
//funtion: 删除指定位置的元素, 并用 element 接受返回的值
//parameter: position-删除位置 element-删除的元素
//return: true is successful, false is faild
//*/
//    bool delete_element(int position, ElemType &element) {
//        if (position < 1 || position > size()) {
//            return false;
//        }
//        int keep_position = position;
//        auto traverse_point = head_point;
//        while (--position) {
//            traverse_point = traverse_point->next;
//        }
//        auto Delete_point = traverse_point->next;
//        element = Delete_point->data;
//        traverse_point->next = Delete_point->next;
//        if (keep_position == size()) {
//            tail_point = traverse_point;
//        }
//        delete Delete_point;
//        Delete_point = nullptr;
//        --m_length;
//        return true;
//    }
//
///*
//funtion: 打印链表
//parameter: none
//return: none
//*/
//    void traverse() {
//        auto traverse_point = head_point->next;
//        while (traverse_point != NULL) {
//            cout << traverse_point->data << " ";
//            traverse_point = traverse_point->next;
//        }
//        cout << endl;
//    }
//
//
//};
//
//}
//
//// template class LinkList<ELemType> OK
//#endif


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
        size_t m_length;
        Node<ElemType> *head_point;
        Node<ElemType> *tail_point;

        /*
        funtion: 默认构造函数
        */
    public:
        LinkList() : m_length(0), head_point(new Node<ElemType>), tail_point(head_point)
        { head_point->next = nullptr; }

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
        ~LinkList() {
            clear();
            delete head_point;
            head_point = tail_point = nullptr;
        }

    public:
        /*
         function: 合并链表
         parameter: rhs-另一个链表
         return: none
         */
        void merge(const LinkList<ElemType>& rhs) {
            if (rhs.empty()) {
                return;
            }
            Node<ElemType> *tailNode = this->tail_point;
            tailNode->next = rhs.head_point->next;              // 左链表尾结点链接右链表的第一个数据结点
            this->m_length += rhs.m_length;                     // 更新长度
            this->tail_point = rhs.tail_point;                  // 更新尾结点

        }


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
            return m_length == 0;
        }

        /*
        funtion: 清空链表
        parameter: none
        return: none
        */
        void clear() {
            // way 1
            /*
                while(!empty()) {
                    delete_element(1);
                }
            */


            // way 2
            auto traverse_point = head_point->next;  // 从头部开始删除
            while (traverse_point) {
                auto delete_point = traverse_point;
                head_point->next = delete_point->next;
                traverse_point = traverse_point->next;  // 一旦 traverse_point 被赋值为 nullptr,说明正在删除最后一个节点
                if (traverse_point == nullptr) {
                    tail_point = head_point;
                }
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
        bool getElem(int position, ElemType &element) const {
            auto traverse_point = head_point->next;
            while (--position && traverse_point != NULL) {
                traverse_point = traverse_point->next;
            }
            if (traverse_point != NULL) {
                element = traverse_point->data;
                return true;
            } else {
                throw "arg error";
            }
        }

        /*
        funtion: 根据位置获取元素
        parameter: 位置-position
        return: 返回 数据域的引用 , 没有找到则抛出异常
        */
        ElemType& getElem(int position) const {
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
        bool setElem(int position, const ElemType &element) {
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
            getElem(position) = element;
            return true;
            // */
        }

        /*
        funtion: 根据元素定位其在链表中的位置
        parameter: 传入元素
        return: 找到的位置,若找不到，则返回 0
        */
        int locate(ElemType x) {
            auto traverse_point = head_point->next;
            unsigned int i = 0;
            while (traverse_point != NULL) {
                ++i;
                if (traverse_point->data == x) {
                    return i;
                } else {
                    traverse_point = traverse_point->next;
                }
            }
            return 0;
        }

        /*
        funtion: 向链表中插入元素
        parameter: positon-插入的位置，e-插入的元素
        return: true is successful false is faild
        */
        bool insert(int position, const ElemType &element) {
            int keep_position = position;
            if (position < 1 || position > size() + 1) {
                return false;
            }
            auto traverse_point = head_point;
            while (--position) {
                traverse_point = traverse_point->next;
            }
            auto new_point = new (Node<ElemType>);
            new_point->data = element;
            new_point->next = traverse_point->next;
            traverse_point->next = new_point;
            if (keep_position == size() + 1) {
                tail_point = new_point;        // tail_point 指向最后一个元素
            }
            ++m_length;
            return true;
        }

        /*
        funtion: 将元素插入在头部
        parameter: element-元素
        return: bool 值
        */
        bool addToHead(const ElemType &element) {
            Node<ElemType> *new_point = new (Node<ElemType>);
            new_point->data = element;
            new_point->next = head_point->next;
            head_point->next = new_point;
            ++m_length;
            return true;
        }

        /*
        funtion: 将元素插入在尾部
        parameter: element-元素
        return: bool 值
        */
        bool addToTail(const ElemType &element) {
            Node<ElemType> *new_point = new (Node<ElemType>);
            new_point->data = element;
            new_point->next = tail_point->next; // nullptr 的传递
            tail_point->next = new_point;        // 链接新节点
            tail_point = new_point;       // tail_point 指向最后一个元素
            ++m_length;
            return true;
        }

        /*
        funtion: 删除指定位置的元素
        parameter: position-删除位置
        return: true is successful, false is faild
        */
        bool deleteElement(int position) {
            if (position < 1 || position > size()) {
                return false;
            }
            int keep_position = position;
            auto traverse_point = head_point;
            while (--position) {
                traverse_point = traverse_point->next;
            }
            auto delete_point = traverse_point->next;
            traverse_point->next = delete_point->next;
            if (keep_position == size()) {  // 删除的是最后一个元素
                tail_point = traverse_point;   // tail_point 指向最后一个元素
            }
            delete delete_point;
            delete_point = nullptr;
            --m_length;
            return true;
        }

        /*
        funtion: 删除指定位置的元素, 并用 element 接受返回的值
        parameter: position-删除位置 element-删除的元素
        return: true is successful, false is faild
        */
        bool deleteElement(int position, ElemType &element) {
            if (position < 1 || position > size()) {
                return false;
            }
            int keep_position = position;
            auto traverse_point = head_point;
            while (--position) {
                traverse_point = traverse_point->next;
            }
            auto Delete_point = traverse_point->next;
            element = Delete_point->data;
            traverse_point->next = Delete_point->next;
            if (keep_position == size()) {
                tail_point = traverse_point;
            }
            delete Delete_point;
            Delete_point = nullptr;
            --m_length;
            return true;
        }

        /*
        funtion: 打印链表
        parameter: none
        return: none
        */
        void traverse() {
            auto traverse_point = head_point->next;
            while (traverse_point != NULL) {
                cout << traverse_point->data << " ";
                traverse_point = traverse_point->next;
            }
            cout << endl;
        }

        /*
        function: 排序单链表
        parametet: none
        return: none
        */
        void sort() {
            Node<ElemType> *pt = head_point->next->next;
            Node<ElemType> *pt2 = nullptr;
            while (pt != nullptr) {
                pt2 = pt->next;

            }
        }



    };


}

// template class LinkList<ELemType> OK
#endif