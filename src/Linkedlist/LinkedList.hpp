#ifndef _LINKLIST__HPP_
#define _LINKLIST__HPP_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 * @date 2023-06-15
 * 
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 * 
 * @brief 链表
 */

namespace mylist {
template <typename T>
class LinkList;

template <typename T>
struct ListItem;

template <typename T>
LinkList<T> merge(LinkList<T> lhs, LinkList<T> rhs);

template<typename T>
const LinkList<T>& sort(LinkList<T>& list);

template<typename T>
LinkList<T> interSect(LinkList<T>& lhs, LinkList<T>& rhs);

template<typename T>
LinkList<T> subs(LinkList<T> lhs, LinkList<T> rhs);
}
namespace mylist {
template<class T>
class LinkList {
public:
    friend LinkList<T> merge<>(LinkList<T> lhs, LinkList<T> rhs); 
    friend const LinkList<T>& sort<>(LinkList<T>& list);
    friend LinkList<T> interSect<>(LinkList<T>& lhs, LinkList<T>& rhs);
    friend LinkList<T> subs<>(LinkList<T> lhs, LinkList<T> rhs);

public:
    LinkList(void);
    LinkList(T target_[], int n);
    LinkList(const LinkList& rhs);
    ~LinkList(void);

public:
    inline bool empty(void) const noexcept { return m_length == 0; }
    inline int size(void) const noexcept { return this->m_length; }

    void clear(void); 
    unsigned contain(const T& x);
    void insert(int pos, const T& val); 
    void push_front(const T& val);
    void push_back(const T& val);
    void erase(int pos);
    void erase(int first, int last);
    void remove(const T& val);
    void traverse(void) const;

    void setLength(size_t length) { m_length = length; }
    void setElem(int pos, const T& val); 

private:
    inline T& getElem(int pos);
    inline const T& getElem(int pos) const;

private:
    struct ListItem {
    public:
        ListItem(void);
        ListItem(const T& val, ListItem *next = nullptr);
        ~ListItem(void);
    public:
        ListItem& operator=(const ListItem& rhs) = delete;
    public:
        T data;
        ListItem *next = nullptr;
    };
private:
    size_t m_length;
    ListItem head;
    ListItem tail;

};

template<typename T>
LinkList<T>::ListItem::ListItem(void) {
    data = T();
}

template<typename T>
LinkList<T>::ListItem::ListItem(const T& val, ListItem* next) : data(val) {
    this->next = next;
}

template<typename T>
LinkList<T>::LinkList() : m_length(0), 
                        head(ListItem()),
                        tail(ListItem()) { }

template<typename T>
LinkList<T>::LinkList(T target_[], int n) : LinkList() {
    for (int i = 0; i < n; ++i) {
        insert(i + 1, target_[i]);  // 可能会造成越界
    }
}

template<typename T>
LinkList<T>::LinkList(const LinkList<T>& rhs) : LinkList() {
    for (int i = 1; i <= rhs.size(); ++i) {
        insert(i, rhs.getElem(i));
    }
}

template<typename T>
LinkList<T>::~LinkList() {
    clear();
}


template<typename T>
void LinkList<T>::clear(void) {
    erase(1, size() + 1);
}

template<typename T>
unsigned LinkList<T>::contain(const T& x) {
    auto traversePoint = head.next;
    unsigned int i = 0;
    while (traversePoint != NULL) {
        ++i;
        if (traversePoint->data == x) {
            return i;
        } else {
            traversePoint = traversePoint->next;
        }
    }
    return 0;
}

template<typename T>
void LinkList<T>::insert(int pos, const T& val) {
    size_t keepPosition = pos--;
    if (pos < 0 || pos > size()) {
        return;
    }
    auto traversePoint = head.next;
    if (pos == 0) {
        auto newPoint = new ListItem(val, traversePoint);
        head.next = newPoint;
        tail.next = newPoint;        // tail_point 指向最后一个元素
    } else {
        while (--pos) {
            traversePoint = traversePoint->next;
        }
        auto newPoint = new ListItem(val, traversePoint->next);
        traversePoint->next = newPoint;
        if (keepPosition == size() + 1) {
            tail.next = newPoint; 
        }
    }
    ++m_length;
}

template<typename T>
void LinkList<T>::push_front(const T& val) {
    auto newPoint = new ListItem(val, head.next);
    head.next = newPoint;
    ++m_length;
}

template<typename T>
void LinkList<T>::push_back(const T& val) {
//    if (tail.next != nullptr) {
//        auto newPoint = new ListItem(val, (tail.next)->next);
//        (tail.next)->next = newPoint;
//        tail.next = newPoint;
//        ++m_length;
//    } else {
//        auto newPoint = new ListItem(val, nullptr);
//        tail.next = newPoint;
//        ++m_length;
//    }
    insert(1, val);
}

template<typename T>
void LinkList<T>::erase(int pos) {          // 返回迭代器
    size_t keepPosition = pos--;
    if (pos < 0 || pos > size()) {
        return;
    }
    auto traversePoint = head.next;
    if (pos == 0) {  // 删除的是第一个元素
        auto deletePoint = traversePoint;   
        head.next = traversePoint->next;
        delete deletePoint;
        deletePoint = nullptr;
    } else {
        while (--pos) {
            traversePoint = traversePoint->next;
        }
        auto deletePoint = traversePoint->next;
        traversePoint->next = deletePoint->next;
        if (keepPosition == size()) {  // 删除的是最后一个元素
            tail.next = traversePoint->next;   // tail_point 指向最后一个元素
        }
        delete deletePoint;
        deletePoint = nullptr;
    }
    --m_length;
}

template<typename T>
void LinkList<T>::erase(const int first, const int last) {  // 左闭右开     // 返回迭代器
    size_t deleteCount = last - first;
    while (deleteCount-- > 0) {
        erase(first);
    }
}

template<typename T>
void LinkList<T>::remove(const T& val) {


}

template<typename T>
void LinkList<T>::traverse() const {
    auto traversePoint = head.next;
    while (traversePoint != NULL) {
        cout << traversePoint->data << " ";
        traversePoint = traversePoint->next;
    }
    cout << endl;
}


template<typename T>
void LinkList<T>::setElem(int pos, const T& val) {
    if (pos < 1 || pos > size()) {
        return;
    }
    getElem(pos) = val;
    return;
}

template<typename T>
T& LinkList<T>::getElem(int pos) {
    auto traversePoint = head.next;
    while (--pos) {
        traversePoint = traversePoint->next;
    }
    return traversePoint->data;
}

template<typename T>
const T& LinkList<T>::getElem(int pos) const {
    auto traversePoint = head.next;
    while (--pos) {
        traversePoint = traversePoint->next;
    }
    return traversePoint->data;
}

/**
 * function: 合并链表
 * parameter: lhs, rhs - 合并链表  右合并到左
 * return: 合并后的链表
 */
    template<typename T>
    LinkList<T> merge(LinkList<T> lhs, LinkList<T> rhs) {
        if (lhs.empty()) {
            return rhs;
        }
        if (rhs.empty()) {
            return lhs;
        }
        int tPos = 0, sizeOfLeft = lhs.size();
        while (++tPos <= rhs.size()) {
            lhs.insert(sizeOfLeft + tPos, rhs.getElem(tPos));
        }
        return lhs;
    }

/**
 * function: 排序单链表
 * parametet: list-排序目标
 * return: none
 */
    template<typename T>
    const LinkList<T>& sort(LinkList<T>& list) {
        auto listHeader = &list.head;
        auto pt = listHeader->next->next;   // 指向首元结点下一结点的指针
        auto pt2 = pt;
        pt2 = nullptr;
        auto pre = listHeader;
        pre = nullptr;
        listHeader->next->next = nullptr;   // 当前链表只有一个首元结点，其指针域为
        while (pt != nullptr) {        // 只有一个数据时，不参加排序
            pt2 = pt->next;
            pre = listHeader;        // 每次获取弄好的新链表头结点
            while (pre->next != nullptr && pre->next->data < pt->data) {
                pre = pre->next;
            }
            pt->next = pre->next;
            pre->next = pt;
            pt = pt2;
        }
        return list;
    }


/**
 * function: 获取两个链表的交集
 * parameter: lhs,rhs 求交集的链表
 * return: 交集
 */
    template<typename T>
    LinkList<T> interSect(LinkList<T>& lhs, LinkList<T>& rhs) {
        LinkList<T> result;
        int iPos = 0, tPos = 0;
        while (++tPos <= lhs.size()) {
            T curValue = lhs.getElem(tPos);
            if (rhs.contain(curValue)) {
                result.insert(++iPos, curValue);
            }
        }
        return result;

    }

/**
 * function: 获取两个链表的差集
 * parameter: lhs,rhs 求差集的链表
 * return: 差集
 */
    template<typename T>
    LinkList<T> subs(LinkList<T> lhs, LinkList<T> rhs) {
        // lhs 的元素不能出现在 rhs 中
        int tPos = 0;
        while (++tPos <= lhs.size()) {
            if (rhs.contain(lhs.getElem(tPos))) {
                // 如果 rhs 中包含了 lhs 的元素，则删除 lhs 中的元素
                // 更新 tPos 指向的位置
                // lhs.deleteElem(tPos--);
                lhs.erase(tPos--);
            }
        }
        return lhs;
    }

}

// template class LinkList<T> OK
#endif