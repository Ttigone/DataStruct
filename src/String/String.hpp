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
class String {
private: 
    size_t m_length;
    char *T;

public:
/*
funtion: 默认构造函数
*/
    String() : m_length(0), T(new char[MAX_LEN]) { }

/*
拷贝构造函数
*/
    String(const String &copy) : String() {
        m_length = copy.size();
        for (int i = 0; i < m_length; ++i) {
            T[i] = copy.T[i];
        }
    }

/*
funtion: 析构函数
*/
    ~String() {
        delete [] T;
        T = nullptr;
    }
    
public:

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

    void str() {
        for (int i = 0; i < size(); ++i) {
            cout << T[i];
        }
    }

    constexpr bool empty() const {
        return m_length == 0;
    }

    constexpr int size() const {
        return m_length;
    }

    bool concat(const String &target) {
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

    bool sub_string(size_t pos, size_t length) {
        if (pos < 1 || pos > size() || pos + length > size() + 1) {
            return false;
        }
        for (int i = pos - 1; i < pos - 1 + length; ++i) {
            cout << T[i];
        }
        return true;
    }

    int index(const String &target, size_t pos = 0) {
        if (pos < 0 || pos >= size()) {
            return 0;
        }
        int i = pos, j = 0;
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

    void clear() {
        m_length = 0;
    }

    bool c_insert(const char &c, int pos) {
        auto move_times = size() - pos + 1;
        auto length = size() - 1;
        while(move_times--) {
            T[length + 1] = T[length];
            length--;
        }
        T[pos - 1] = c;
        ++m_length;
        return true;
    }

    bool str_insert(const String &target, int pos) {
        auto all_length = size() + target.size();
        if (all_length > MAX_LEN) {
            return false;
        }
        for (int i = 1; i <= target.size(); ++i) {
            c_insert(target.T[i - 1], pos + i);
        }
        return true;
    }

    bool c_delete(int pos) {
        if (pos < 1 || pos > size()) {
            return false;
        }
        for (int i = pos; i < size(); ++i) {
            T[i - 1] = T[i];
        }
        --m_length;
        return true;
    }

    bool str_delete(int pos, size_t length) {
        if (pos < 1 || pos > size()) {
            return false;
        }
        for (int i = pos, t = 0; t < length; ++t) {
            c_delete(i);
        }
        return true;
    }

};



}

// template class String OK
#endif