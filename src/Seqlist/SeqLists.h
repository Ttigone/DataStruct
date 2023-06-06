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
        SeqList(); 
    public:
        SeqList(const ElemType* target, int n);  // 有参构造   n 代表 a 中前多少个元素被复制
        int Length() const noexcept; 
        bool Empty() const; 
        void Clear();
        void Traverse(void (*visitr)(const ElemType &)) const; 
        ElemType GetElem(int position, ElemType &e) const; 
        bool SetElem(int position, const ElemType &e); 
        int Locate(const ElemType& parameter, int a = 0);   // 返回定位的位置  二分搜索
        // 有序数组, 才能用二分搜索
        void Insert(int position, const ElemType& x);  // 在第 i 个位置插入元素，其余元素后移动 
        void Delete(int position, ElemType &e); 
        void Delete(int position);    // 不返回删除的元素
        void Delete_Element(const ElemType &element, int label = 0); 
        void Detele_repeated_element() noexcept;   // 无序表
        ~SeqList();
    private:
        ElemType data[MAXSIZE];
        int length = 0;
    };
}


#endif