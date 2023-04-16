#ifndef _DEQUE__HPP_
#define _DEQUE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

constexpr int QueueSize = 100;

namespace my_deque {
    template<class ElemType>
    class Deque {
    public:
        Deque();
        ~Deque();
        void EnQueue(int i, ElemType x);
        ElemType DeQueue(int i);
        ElemType GetQueue(int i);
        int Length();
        int Empty();
        void Print();
    private:
        ElemType data[QueueSize];
        int front, rear;
    };
}

#endif