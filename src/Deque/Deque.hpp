#ifndef _DEQUE__HPP_
#define _DEQUE__HPP_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <class ElemType>
class Deque {
public:
    Deque() {}
    ~Deque() {}
    
private:

public:
/*
funtion: 获取长度
parameter: none
return: 长度
*/
    int length() const {
        return 0;
    }

/*
funtion: 判断队列是否为空
parameter: none
return: true is empty false is no empty
*/
    bool empty() const {
        return true;       
    }

/*
funtion: 清空队列
parameter: none
return: none
*/
    void clear() {

    }

/*
funtion: 遍历元素
parameter: none
return: none
*/
    void traverse() const {

    }

/*
funtion: 在对头删除元素,并用存储值
parameter: e-存储值 
return: true is successful false is faild
*/
    bool out_queue(ElemType &e) {
        return true;
    }

/*
funtion: 在对头删除元素
parameter: none
return: true is successful false is faild
*/
    bool out_queue() {
        return true;
    }

/*
funtion: 获取对头元素
parameter: e-存储元素
return: true is successful false is faild
*/
    bool get_head(ElemType &e) const {
        return true;
    }

/*
funtion: 插入元素到队尾
parameter: e-待插入元素
return: true is successful false is faild 
*/
    bool in_queue(const ElemType &e){
        return true;
    }
};


#endif