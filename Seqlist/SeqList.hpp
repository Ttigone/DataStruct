#ifndef _SEQLIST__HPP_
#define _SEQLIST__HPP_

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
constexpr int MAXSIZE = 100;

namespace my_seqlist {
    template <class ElemType>
    class SeqList {
    public:
        SeqList() {length = 0;}
    public:
        inline SeqList(const ElemType* target, int n) {  // 有参构造   n 代表 a 中前多少个元素被复制
            if (n > MAXSIZE) {
                throw "args is invaild";
            }
            for (int i = 0; i < n; ++i) {
                data[i] = target[i];
            }
            length = n;
        }
        inline int Length() const noexcept {
            return length;
        }
        inline ElemType Get(int i) const {
            if (i < 1 || i > length) {
                throw "arg is invaild";
            }
            return data[i - 1];
        }
        inline int Locate(const ElemType& parameter, int a = 0) {  // 返回定位的位置  二分搜索
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
                if (data[i] == parameter) {
                    return i + 1;
                }
            }
            return 0;
        } // 有序数组, 才能用二分搜索
        inline void Insert(int i, const ElemType& x) {  // 在第 i 个位置插入元素，其余元素后移动 
            if (length > MAXSIZE - 1) {        // 存储结构满了
                throw "sorry! Storage space of full";
            }
            if (i < 1 || i > length + 1) {    // 存储结构的顺序反映了数据的顺序
                throw "arg is invalid"; 
            }
            for (auto j = length; j > i - 1; --j) {
                data[j] = data[j - 1];
            }
            data[i - 1] = x;
            ++length;
        }
        inline void Delete(int i) {
            if (i < 1 || i > length) {
                throw "arg is invaild";
            }
            for (auto j = length; i < j; ++i) {
                data[i - 1] = data[i];
            }
            data[length--] = 0;
        }
        inline void PrintList() const noexcept {
            if (!length) {
                cout << "The storage is empty" << endl;
                return;
            }
            for (auto i{0}; i < length; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        inline void Delete_Element(const ElemType &element, int label = 0) {

//***********************************************************************//
//  双指针法,并未改变原有数据顺序,但仍保留在数组中
            int slow_point = 0;
            int fast_point = 0;
            for (; fast_point < this->length; ++fast_point) {
                if (element != data[fast_point]) {
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
        inline void Detele_repeated_element() noexcept {  // 无序表
            for (int i = 0; i < Length(); ++i) {
                for (int j = i + 1; j < Length(); ++j) {
                    if (data[i] == data[j]) {
                        Delete(j + 1);
                    }
                }
            }
        }
        void Merge(SeqList<ElemType> &L1, SeqList<ElemType> &L2, SeqList<ElemType> &L3) {
            int i = 1, j = 1, k = 1;
            int n1 = L1.Length();
            int n2 = L2.Length();
            while (i <= n2 && j <= n2) {
                if (Get(i) <= Get(j)) {
                    L3.Insert(k, Get(i));
                    ++i;
                } else {
                    L3.Insert(k, Get(j));
                    ++j;
                }
                k++;
            }
            while (i <= n1) {
                L3.Insert(k, Get(i));
                ++i;
                ++k;
            }
            while (j <= n2) {
                L3.Insert(k, Get(j));
                ++j;
                ++k;
            }
        }
        inline ~SeqList() = default;
    private:
        ElemType data[MAXSIZE];
        int length = 0;
    };
}


#endif