#ifndef _CIRQUEUE__HPP_
#define _CIRQUEUE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

constexpr int QueueSize = 100;
namespace my_cirqueue {
    template<class ElemType>
    class CirQueue {
    public:
        CirQueue();
        ~CirQueue();
        void EnQueue(ElemType x);
        ElemType DeQueue();
        ElemType GetQueue();
        int Length();
        int Empty();
    private:
        ElemType data[QueueSize];
        int front, rear;
    };
}

#endif