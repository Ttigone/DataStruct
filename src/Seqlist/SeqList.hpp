#ifndef _SEQLIST__HPP_
#define _SEQLIST__HPP_

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;


namespace myseq {
template <class ElemType>
class SeqList {
private:
    ElemType *data;
    int m_length;
    int max_size;
public:
/*
funtion: 默认构造函数
*/
    SeqList() = default;

/*
funtion: 有参构造函数，赋值
parameter: target-目标数组的指针 n-赋值个数
return:none
*/
    // SeqList(const ElemType* target, int n) { 
    //     if (n > MAXSIZE) {
    //         throw "args is invaild";
    //     }
    //     for (int i = 0; i < n; ++i) {
    //         data[i] = target[i];
    //     }
    //     m_length = n;
    // }

/*
funtion: 有参构造函数 
*/
    SeqList(int init_size = 10) { 
        if (init_size <= 0) {
            throw new std::logic_error("size error");
        }
        max_size = init_size;
        data = new ElemType[max_size];
        m_length = 0;
    }
/*
funtion: 拷贝构造函数
*/
    SeqList(SeqList &copy) : max_size(copy.m_size), m_length(copy.m_length){
        data = new ElemType[max_size];
        for (int i = 0; i < m_length; ++i) {
            data[i] = copy.data[i];
        }
    }

/*
funtion: 析构函数
parameter: none
return: none
*/
    ~SeqList() {
        delete [] data;
        data = nullptr;
    }
    
/*
funtion: 获取长度
parameter: none
return: 长度
*/
    constexpr int size() noexcept {
        return m_length;
    }

/*
funtion: 设置当前有效长度
parameter: none
return: 长度的引用
*/
    constexpr int& set_size() {
        return m_length;
    }

/*
funtion: 获取可存储的最大长度
parameter: none
return: 可存储最大长度
*/
    constexpr int m_size() noexcept {
        return max_size;
    }

/*
funtion: 重新分配长度
parameter: none
return: none
*/
    void resize() noexcept {
        std::vector<ElemType> copy;
        for (int i = 0; i < size(); ++i) {
            copy.push_back(data[i]);
        }
        max_size = max_size + max_size / 2;
        data = new ElemType[max_size];
        for (int t = 0; t < size(); ++t) {
            data[t] = copy[t];
        }
    }

/*
funtion: 判断是否为空
parameter: none
return: true is empty false is no empty
*/
    constexpr bool empty() const {
        if(!size()) {
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
    void clear() {
        // for (auto &i : data) {
        //     i = 0;
        // }
        for (int i = 0; i < size(); ++i) {
            data[i] = 0;
        }
        set_size() = 0;
    }

/*
funtion: 遍历输出顺序表
parameter: none
return: none
*/
    void traverse() const {
        cout << "output element: ";
        for (auto i = 0; i < size(); ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

/*
funtion: 逆置顺序表
parameter: none
return: none
*/   
    void inverse() {
        auto s = size();
        for (int i = 0; i < s / 2; ++i) {
            std::swap(data[i], data[s - 1 - i]);
        }
    }

/*
funtion: 获取指定位置的元素
parameter: position-指定位置  e-存储元素
return: none
*/
    void get_elem(int position, ElemType &e) const {
        if (position < 1 || position > size()) {
            throw "arg is invaild";
        }
        e = data[position - 1];
    }
    
/*
funtion: 为指定位置设定元素
parameter: position-指定位置 element-设定的元素
return: true is successful false is faild
*/
    bool set_elem(int position, const ElemType &element) {
        if (position < 1 || position > size()) {
            return false;
        }
        data[position - 1] = element;
        return true;
    }
    
/*
funtion: 根据指定元素定位，首个元素位置
parameter: 定位元素
return: 返回位置  没有查找到就返回 0
*/
    int locate(const ElemType &e) {  // 返回定位的位置  二分搜索
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
        for (int i = 0; i < size(); ++i) {
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
    void insert(int position, const ElemType& e) {  // 在第 i 个位置插入元素，其余元素后移动 
        if (size() > max_size - 1) {        // 存储结构满了
            throw "sorry! Storage space of full";
        }
        if (position < 1 || position > size() + 1) {    // 存储结构的顺序反映了数据的顺序
            throw "arg is invalid"; 
        }
        for (auto j = size(); j > position - 1; --j) {
            data[j] = data[j - 1];
        }
        data[position - 1] = e;
        ++set_size();
    }

/*
funtion: 删除指定位置的元素
parameter: position-删除的位置 e-存储删除的元素
return: none
*/
    void delete_position(int position, ElemType &e) {
        if (position < 1 || position > size()) {
            throw "arg is invaild";
        }
        e = data[position - 1];
        for (auto j = size(); position < j; ++position) {
            data[position - 1] = data[position];
        }
        data[set_size()--] = 0;
    }
    
/*
funtion: 删除指定位置的元素
parameter: position-删除的位置 
return: none
*/
    void delete_position(int position) {   // 不返回删除的元素
        if (position < 1 || position > size()) {
            throw "arg is invaild";
        }
        for (auto j = size(); position < j; ++position) {
            data[position - 1] = data[position];
        }
        data[set_size()--] = 0;
    }

/*
funtion: 删除顺序表中连续的重复的元素
parameter: none
return: none
*/
    void delete_element(const ElemType &e) {
//***********************************************************************//
//  双指针法,并未改变原有数据顺序,但仍保留在数组中
        int slow_point = 0;
        int fast_point = 0;
        for (; fast_point < this->m_length; ++fast_point) {
            if (e != data[fast_point]) {
                data[slow_point++] = data[fast_point];
            }
        }
        // cout  << slow_point;
        // cout << '\n' << data[0] << " " << data[1];
        set_size() = slow_point;
        // if (label) {
        //     PrintList();
        // }
        // cout << fast_point - slow_point;

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
funtion: 合并两个顺序表   前提是两个顺序表的非递减的
parameter: 
return: none
*/
    bool merge(SeqList<ElemType> &merge_target) {
        int m, n, k, i, j;
        m = size();
        n = merge_target.size();
        k = m + n - 1;
        i = m - 1, j = n - 1;
        while (m + n > m_size()) {
            resize();
        }
        while(i >= 0 && j >= 0) {
            if (data[i] >= merge_target.data[j]) {
                data[k--] = data[i--];
            } else {
                data[k--] = merge_target.data[j--];
            }
            while(j >= 0) {
                data[k--] = merge_target.data[j--];
            }
            set_size() = m + n;
        }
        return true;
    }

    void operator [](int i) {
        return data[i - 1];
    }


};

}

// template class SeqList<ElemType> OK
#endif