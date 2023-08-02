#ifndef _STRING__HPP_
#define _STRING__HPP_ 

#include <iostream>
#include <string>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

#define MAX_LEN  88

namespace mystring {
class mString {
private: 
    size_t m_length;
    char *T;

public:
/*
funtion: 默认构造函数
*/
    mString() : m_length(0), T(new char[MAX_LEN]) { }

/*
拷贝构造函数
*/
    mString(const mString &copy) : mString() {
        m_length = copy.size();
        for (int i = 0; i < m_length; ++i) {
            T[i] = copy.T[i];
        }
    }

/*
funtion: 析构函数
*/
    ~mString() {
        delete [] T;
        T = nullptr;
    }
    
public:

/*
funtion: 值等于 chars 的串 target
parameter: 模板串 T
return: bool is successful
*/
    bool str_assign(char *target) {
        m_length = strlen(target);
        if (m_length > MAX_LEN) {
            return false;
        }
        for (int i = 0; i < m_length; ++i) {
            T[i] = target[i];
        }
        return true;
    }

/*
funtion: 返回字符串
parameter: none
return: none
*/
    void str() {
        for (int i = 0; i < size(); ++i) {
            cout << T[i];
        }
    }

/*
funtion: 判断串是否为空
parametet: none
return: true is empty false is no empty
*/
    constexpr bool empty() const {
        return m_length == 0;
    }

/*
funtion: 获取字符串个字符个数
parameter: none
return: 字符个数
*/
    constexpr int size() const {
        return m_length;
    }

/*
funtion: 链接字符串 
parameter: target-目标字符串 
return: true is successful  
*/
    bool concat(const mString &target) {
        auto all_length = size() + target.size();
        if (all_length > MAX_LEN) {
            return false;
        }
        // m_length = all_length;
        for (int t = 0, i = size(); i < all_length; ++i, ++t) {
            T[i] = target.T[t];
        }
        m_length = all_length;
        return true;
    }

/*
funtion: 求从第 pos 个字符开始长度为 length 的子串
parameter: position-位置 length-长度
return: none
*/
    bool sub_string(size_t position, size_t length) {
        if (position < 1 || position > size() || position + length > size() + 1) {
            return false;
        }
        for (int i = position - 1; i < position - 1 + length; ++i) {
            cout << T[i];
        }
        return true;
    }

/*
funtion: 求取串中第 position 个字符后第一次出现的模式串 pattern
parameter: target-目标串 position-位置 
return: 获取的位置,若不存在，则返回 0 
*/
    int index(const mString &target, size_t position = 0) {
        if (position < 0 || position >= size()) {
            return 0;
        }
        int i = position, j = 0;
        while (i <= size() - 1) {
            int k = i;
            while (T[k++] == target.T[j++]){  // 匹配时
                if (j == target.size()) {  // 成功匹配
                    return i + 1;
                }
            }
            j = 0;   //模式串的索引置位起始位置 
            ++i;     // 匹配串 索引后移
        }
        return 0;
    }

/*
funtion: 清空字符串
parameter: none
return: none
*/
    void clear() {
        m_length = 0;
    }

/*
funtion: 在串中 第 position 个位置插入一个字符
parameter: c-待插入字符 position-位置
return: true is successful
*/
    bool c_insert(const char &c, int position) {
        auto move_times = size() - position + 1;
        auto length = size() - 1;
        while(move_times--) {
            T[length + 1] = T[length];
            length--;
        }
        T[position - 1] = c;
        ++m_length;
        return true;
    }

/*
funtion: 在 position 个字符后面插入 串T
parameter: position-位置 target-目标串
return: true is successful
*/
    bool str_insert(const mString &target, int position) {
        auto all_length = size() + target.size();
        if (all_length > MAX_LEN) {
            return false;
        }
        for (int i = 1; i <= target.size(); ++i) {
            c_insert(target.T[i - 1], position + i);
        }
        return true;
    }

/*
funtion: 删除第 position 个字符
parameter: position-位置
return: true is successful
*/
    bool c_delete(int position) {
        if (position < 1 || position > size()) {
            return false;
        }
        for (int i = position; i < size(); ++i) {
            T[i - 1] = T[i];
        }
        --m_length;
        return true;
    }

/*
funtion: 删除自 position 个字符长度为 length 的字串
parameter: position-起始位置 length-长度
return: true is successful
*/
    bool str_delete(int position, size_t length) {
        if (position < 1 || position > size()) {
            return false;
        }
        for (int i = position, t = 0; t < length; ++t) {
            c_delete(i);
        }
        return true;
    }

};

}

// template class mString OK
#endif