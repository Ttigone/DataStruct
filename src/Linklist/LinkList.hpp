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
namespace my_linklist {
    template<class ElemType>
    class LinkList {
    public:
        LinkList();
        ~LinkList();
        LinkList(ElemType a[], int n) {
            
        }
        int Length() {
            int count = 0;
            auto p = first->next;
            while (p != NULL) {
                ++count;
                p = p->next;
            }
            return count;
        }
        ElemType Get(int i) {
            auto p = first->next;
            while (--i && p != NULL) {
                p = p->next;
            }
            if (p != NULL) {
                return p->data;
            } else {
                throw "arg error";
            }
        }
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
        void Insert(int i, ElemType x) {
            auto p = first->next;

        }
        ElemType Delete(int i);
        void PrintList() {
            auto p = first->next;
            while (p != NULL) {
                cout << p->data;
                p = p->next;
            }
        }
    private:
        Node<ElemType> *first;  
    };
}

#endif

