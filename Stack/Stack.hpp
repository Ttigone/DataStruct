#ifndef _STACK__HPP_
#define _STACK__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace my_stack {
    template<class ElemType>
    class Stack {
    public:
        Stack();
        ~Stack();
        void Push(int i, ElemType x);
        ElemType Pop(int i);
        ElemType GetTop(int i);
        int Empty(int i);
    private:
        ElemType data[StackSize];
        int top1;
        int top2;
    };
}

#endif