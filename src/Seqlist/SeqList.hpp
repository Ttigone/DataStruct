#ifndef _SEQLIST__HPP_
#define _SEQLIST__HPP_

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
constexpr int MAXSIZE = 100;


template <class ElemType>
class SeqList {
public:
    SeqList() {length = 0;}
    ~SeqList() = default;
private:
    ElemType data[MAXSIZE];
    int length = 0;
public:
/*
funtion: 有参构造函数，赋值
parameter: target-目标数组的指针 n-赋值个数
return:none
*/
    SeqList(const ElemType* target, int n) { 
        if (n > MAXSIZE) {
            throw "args is invaild";
        }
        for (int i = 0; i < n; ++i) {
            data[i] = target[i];
        }
        length = n;
    }

/*
funtion: 获取长度
parameter: none
return: 长度
*/
    int Length() const noexcept {
        return length;
    }

/*
funtion: 判断是否为空
parameter: none
return: true is empty false is no empty
*/
    bool Empty() const {
        if(!Length()) {
            return true;
        } else {
            return false;
        }
    }

/*
funtion: 清空顺序表, 长度变为 0
parameter: none
return: none
*/
    void Clear() {
        for (auto &i : data) {
            i = 0;
        }
        this->length = 0;
    }

/*
funtion: 遍历输出顺序表
parameter: none
return: none
*/
    void Traverse() const {
        for (auto i = 0; i < Length(); ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
/*
funtion: 获取指定位置的元素
parameter: position-指定位置  e-存储元素
return: none
*/
    ElemType GetElem(int position, ElemType &e) const {
        if (position < 1 || position > Length()) {
            throw "arg is invaild";
        }
        return data[position - 1];
    }
    
/*
funtion: 为指定位置设定元素
parameter: position-指定位置 e-设定的元素
return: true is successful false is faild
*/
    bool SetElem(int position, const ElemType &e) {
        if (position < 1 || position > Length()) {
            return false;
        }
        e = data[position - 1];
    }
    
/*
funtion: 根据指定元素定位，首个元素位置
parameter: 定位元素
return: 返回位置  没有查找到就返回 0
*/
    int Locate(const ElemType &e) {  // 返回定位的位置  二分搜索
        // unsigned int left = a;
        // unsigned int right = length;
        // while (left <= right) {
        //     int middle = (left >> 1) + (right >> 1);
        //     if (data[middle] < parameter) {
        //         left = middle + 1;
        //     } else if (data[middle] > parameter) {
        //         right = middle - 1;
        //     } else {
        //         return middle;  // 返回下标
        //     }
        // }
        // return 0;   // 没有找到就返回 0
        for (int i = 0; i < Length(); ++i) {
            if (data[i] == e) {
                return i + 1;
            }
        }
        return 0;
    } // 有序数组, 才能用二分搜索

/*
funtion: 向顺序表中插入元素
parameter: position-插入位置 e-插入的元素
return: none
*/
    void Insert(int position, const ElemType& e) {  // 在第 i 个位置插入元素，其余元素后移动 
        if (this->length > MAXSIZE - 1) {        // 存储结构满了
            throw "sorry! Storage space of full";
        }
        if (position < 1 || position > length + 1) {    // 存储结构的顺序反映了数据的顺序
            throw "arg is invalid"; 
        }
        for (auto j = this->length; j > position - 1; --j) {
            data[j] = data[j - 1];
        }
        data[position - 1] = e;
        ++this->length;
    }

/*
funtion: 删除指定位置的元素
parameter: position-删除的位置 e-存储删除的元素
return: none
*/
    void Delete(int position, ElemType &e) {
        if (position < 1 || position > length) {
            throw "arg is invaild";
        }
        e = data[position - 1];
        for (auto j = length; position < j; ++position) {
            data[position - 1] = data[position];
        }
        data[length--] = 0;
    }
    
/*
funtion: 删除指定位置的元素
parameter: position-删除的位置 
return: none
*/
    void Delete(int position) {   // 不返回删除的元素
        if (position < 1 || position > length) {
            throw "arg is invaild";
        }
        for (auto j = length; position < j; ++position) {
            data[position - 1] = data[position];
        }
        data[length--] = 0;
    }

/*
funtion: 删除顺序表中连续的重复的元素
parameter: none
return: none
*/
    void Delete_Element(const ElemType &e) {
//***********************************************************************//
//  双指针法,并未改变原有数据顺序,但仍保留在数组中
        int slow_point = 0;
        int fast_point = 0;
        for (; fast_point < this->length; ++fast_point) {
            if (e != data[fast_point]) {
                data[slow_point++] = data[fast_point];
            }
        }
        cout  << slow_point;
        cout << '\n' << data[0] << " " << data[1];
        this->length = slow_point + 1;
        // if (label) {
        //     PrintList();
        // }
        cout << fast_point - slow_point;

//***********************************************************//

// 双指针法,但是打乱原有顺序, 数据仍保留在数组中
        // int size = Length();
        // int leftIndex = 0;
        // int rightIndex = size - 1;
        // while (leftIndex <= rightIndex) {
        //     // 找左边等于val的元素
        //     while (leftIndex <= rightIndex && data[leftIndex] != element){
        //         ++leftIndex;
        //     }
        //     // 找右边不等于val的元素
        //     while (leftIndex <= rightIndex && data[rightIndex] == element) {
        //         -- rightIndex;
        //     }
        //     // 将右边不等于val的元素覆盖左边等于val的元素
        //     if (leftIndex < rightIndex) {
        //         data[leftIndex++] = data[rightIndex--];
        //     }
        // }
        // // return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
        // this->length = leftIndex - 1;
        // if (label) {
        //     PrintList();
        // }
    }
    
/*
funtion: 删除顺序表中重复的元素（可不连续）
parameter: none
return: none
*/
    void Detele_repeated_element() noexcept {  // 无序表
        for (int i = 0; i < Length(); ++i) {
            for (int j = i + 1; j < Length(); ++j) {
                if (data[i] == data[j]) {
                    Delete(j + 1);
                }
            }
        }
    }
    // void Merge(SeqList<ElemType> &L1, SeqList<ElemType> &L2, SeqList<ElemType> &L3) {
    //     int i = 1, j = 1, k = 1;
    //     int n1 = L1.Length();
    //     int n2 = L2.Length();
    //     while (i <= n2 && j <= n2) {
    //         if (Get(i) <= Get(j)) {
    //             L3.Insert(k, Get(i));
    //             ++i;
    //         } else {
    //             L3.Insert(k, Get(j));
    //             ++j;
    //         }
    //         k++;
    //     }
    //     while (i <= n1) {
    //         L3.Insert(k, Get(i));
    //         ++i;
    //         ++k;
    //     }
    //     while (j <= n2) {
    //         L3.Insert(k, Get(j));
    //         ++j;
    //         ++k;
    //     }
    // }
};
// template class SeqList<int>;

#endif