#ifndef _LINKLIST__HPP_
#define _LINKLIST__HPP_

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

namespace my_linklist {
    template<class ElemType>
    class LinkList {
    public:
        LinkList();
        ~LinkList();
        LinkList(ElemType a[], int n);
        int Length();
        ElemType Get(int i);
        int Locate(ElemType x);
        void Insert(int i, ElemType x);
        ElemType Delete(int i);
        void PrintList();
    private:
        Node<ElemType> *first;  
    };
}

#endif
