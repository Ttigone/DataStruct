#ifndef _STACK__HPP_
#define _STACK__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

constexpr int StackSize = 100;

namespace my_stack {
    template<class ElemType>
    class Stack {
    public:
        Stack();
        ~Stack();
    private:
        ElemType data[StackSize];
        int top1;
        int top2;
    public:
/*
funtion: 返回链表长度
parameter: none
return: 长度 length 
*/
        int Length() const {

        }
    
/*
funtion: 判断栈是否为空
parameter: none
return: true is empty false is no empty
*/
        void Empty() const {

        }

/*
funtion: 清空栈
parameter: none
return: none
*/
        void Clear() {

        }

/*
funtion: 入栈
parameter: 入栈元素 
return: none 
*/
        void Push(const ElemType &e) {

        }
    
/*
funtion: 出栈
parameter: 存储出栈元素
return: true is successful false is faild
*/
        bool Pop(const ElemType &e) {

        }
    
/*
funtion: 出栈
parameter: none
return: true is successful false is faild 
*/
        bool Pop() {

        }

/*
funtion: 获取栈顶元素
parameter: none
return: 栈顶元素
*/
        ElemType GetTop() {

        }

    };
}

#endif