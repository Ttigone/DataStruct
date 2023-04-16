#ifndef _LINKQUEUE__HPP_
#define _LINKQUEUE__HPP_

#include <iostream>

using std::cin; 
using std::cout; 
using std::endl;

namespace my_linkqueue {
    template<class ElemType>
    class LinkQueue {
    public:
        LinkQueue();
        ~LinkQueue();
        void EnQueue(ElemType x);
        ElemType DeQueue();
        ElemType GetQueue();
        int Empty();
    private:
        Node<ElemType> *front, *rear;
    };
}

#endif