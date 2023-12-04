#ifndef _STRING__HPP_
#define _STRING__HPP_ 

#include <iostream>
#include <string>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

/**
 * @date 2023-11-7
 *
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 *
 * @brief 顺序串
 */

<<<<<<< HEAD
namespace myseqstring {
	#define MAX_LEN 88
    class String;
    size_t BF(const String& lhs, const String& rhs);

    std::istream& operator>>(std::istream& is, const String& s);
}

namespace myseqstring {

class String {
public:
    String(void);
    String(const String& rhs);
    ~String(void);

public:
    size_t size() const noexcept { return m_length; }
    bool empty() const noexcept { return m_length == 0; }

public:
    bool assign(char *target);
    bool assign(const std::string& target);
    bool concat(const String &target);
    char* subStr(size_t pos, size_t len = -1);
    void insert(const char &c, int pos);
    void erase(size_t pos, size_t len = -1);
    void clear(void);

public:
    char& at(size_t pos);
    const char& at(size_t pos) const ;
    void show(void);
    char& operator[](size_t pos);
    const char& operator[](size_t pos) const ;

private:
    size_t m_length;
    char *T;

=======
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

>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea
};


String::String() : m_length(0), T(new char[MAX_LEN]) { }

String::String(const String &rhs) : String() {
    m_length = rhs.size();
    for (int i = 0; i < m_length; ++i) {
        T[i] = rhs.T[i];
    }
}

String::~String() {
    delete [] T;
    T = nullptr;
}

bool String::assign(char *target) {
    m_length = strlen(target);
    if (m_length > MAX_LEN) {
        return false;
    }
    for (int i = 0; i < m_length; ++i) {
        T[i] = target[i];
    }
    return true;
}

bool String::assign(const std::string& target) {
    m_length = target.size();
    if (m_length > MAX_LEN) {
        return false;
    }
    for (int i = 0; i < m_length; ++i) {
        T[i] = target[i];
    }
    return true;
}

bool String::concat(const String &target) {
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

char* String::subStr(size_t pos, size_t len) {
    if (pos < 1 || pos > size() || pos + len > size() + 1) {
        return nullptr;
    }
    for (int i = pos - 1; i < pos - 1 + len; ++i) {
        cout << T[i];
    }
    return nullptr;
}

void String::erase(size_t pos, size_t len) {
    if (pos < 1 || pos > size()) {
    }
    for (int i = pos, t = 0; t < len; ++t) {
//            c_delete(i);
    }
}

void String::clear() {
    m_length = 0;
}


char& String::at(size_t pos) {
    return T[pos];
}

const char& String::at(size_t pos) const {
    return T[pos];
}

void String::show(void) {
    for (int i = 0; i < m_length; ++i) {
        cout << T[i];
    }
}

char& String::operator[](size_t pos) {
    return this->at(pos);
}

const char& String::operator[](size_t pos) const {
    return this->at(pos);
}


//    bool String::c_insert(const char &c, int pos) {
//        auto move_times = size() - pos + 1;
//        auto length = size() - 1;
//        while(move_times--) {
//            T[length + 1] = T[length];
//            length--;
//        }
//        T[pos - 1] = c;
//        ++m_length;
//        return true;
//    }

//    bool String::str_insert(const String &target, int pos) {
//        auto all_length = size() + target.size();
//        if (all_length > MAX_LEN) {
//            return false;
//        }
//        for (int i = 1; i <= target.size(); ++i) {
//            c_insert(target.T[i - 1], pos + i);
//        }
//        return true;
//    }

//    bool String::c_delete(int pos) {
//        if (pos < 1 || pos > size()) {
//            return false;
//        }
//        for (int i = pos; i < size(); ++i) {
//            T[i - 1] = T[i];
//        }
//        --m_length;
//        return true;
//    }

size_t BF(const String& lhs, const String& rhs) {
    int i = 0;
    int j = 0;
    while (j < lhs.size()) {
        int t = j + 1;
        while (i < rhs.size()) {
            if (rhs.at(i) == lhs.at(j)) {
                ++i; ++j;
            } else {
                i = 0;
                j = t++;
            }
            if (j == lhs.size()) {
                return 0;
            }
        }
        if (i == rhs.size()) {
            return t - 1;
        }
    }
    return 0;
}


std::istream& operator>>(std::istream& is, String& s) {
    std::string str;
    is >> str;
    s.assign(str);
    return is;
}

}   // 顺序串



/**
 * @date 2023-11-7
 *
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 *
 * @brief 链串
 */
namespace myliststring {
    class String;
    std::ostream& operator<<(std::ostream& os, const String& rhs);

    String publicString(const String& lhs, const String& rhs);

    bool palindromicString(const String& val);
}
namespace myliststring {
class String {
public:
    String();
    String(const String& rhs);
    String(const char* s);
    ~String();

public:
    size_t size(void) const noexcept { return m_length; }
    bool empty(void) const noexcept { return m_length == 0; }

public:
    String& append(size_t n, const char& c);
    String& assign(const String& str);
    String& assign(const String& str, size_t subPos, size_t subLen);
    String& assign(const char* s);
    String& assign(const char* s, size_t n);
    String& assign(size_t n, const char& c);
    void push_back(const char& c);
    void erase(size_t pos);
    String& erase(size_t pos, size_t len);       // pos 为下标
    void clear(void) noexcept ;
    int find(const char& c);

public:
    char& at(size_t pos);
    const char& at(size_t pos) const ;
    char& operator[](size_t pos) ;
    const char& operator[](size_t pos) const ;

private:
    struct StringItem {
    public:
        StringItem(void);
        StringItem(const char& val, StringItem* next = nullptr);
    public:
        StringItem& operator=(const StringItem& rhs) = delete;
    public:
        char data;
        StringItem *next;
    };

private:
    size_t m_length;
    StringItem head;

};

String::StringItem::StringItem(void) : data(), next(nullptr) { }

String::StringItem::StringItem(const char& val, StringItem* next) : data(val) {
    this->next = next;
}

String::String(void) : m_length(0), head() { }

String::String(const String& rhs) : String() {
    this->assign(rhs);
}

String::String(const char* s) : String() {
    this->assign(s);
}

String::~String() {
    clear();
}

String& String::append(size_t n, const char& c) {
    for (size_t i = 0; i < n; ++i) {
        push_back(c);
    }
    return *this;
}

String& String::assign(const String& str) {
    this->clear();
    for (size_t i = 0; i < str.size(); ++i) {
        this->push_back(str.at(i));
    }   
    return *this;
}

String& String::assign(const String& str, size_t subPos, size_t subLen) {
    this->clear();
    for (size_t i = subPos; subLen > 0; ++i, --subLen) {
        this->push_back(str.at(i));
    }
    return *this;
}

String& String::assign(const char* s) {
    this->clear();
    size_t n = strlen(s);
    for (size_t i = 0; i < n; ++i) {
        push_back(s[i]);
    }
    return *this;
}

String& String::assign(const char* s, size_t n) {
    this->clear();
    for (size_t i = 0; i < n; ++i) {
        this->push_back(s[i]);
    }
    return *this;
}

String& String::assign(size_t n, const char& c) {
    this->clear();
    for (size_t i = 0; i < n; ++i) {
        push_back(c);
    }
    return *this;
}

void String::push_back(const char& c) {
    auto traversePoint = &head;
    while (traversePoint->next != nullptr) {
        traversePoint = traversePoint->next;
    }
    StringItem* newPoint = new StringItem(c, nullptr);
    traversePoint->next = newPoint;
    ++m_length;
}

void String::erase(size_t pos) {
    auto traversePoint = &head;
    while (pos--) {
        traversePoint = traversePoint->next;
    }
    auto deletePoint = traversePoint->next;
    traversePoint->next = deletePoint->next;
    delete deletePoint;
    deletePoint = nullptr;
    --m_length;
}

String& String::erase(size_t pos, size_t len) {
    while (len--) {
        erase(pos);
    }
    return *this;
}     

void String::clear(void) noexcept {
    erase(0, m_length);
}

int String::find(const char& c) {
    for (int i = 0; i < m_length; ++i) {
        if (at(i) == c) {
            return i;
        }
    }
    return -1;
}

char& String::at(size_t pos) {
    auto traversePoint = head.next;
    while (pos--) {
        traversePoint = traversePoint->next;
    }
    if (traversePoint == nullptr) {
        // throw::out_of_range("Invalid");
    }
    return traversePoint->data;
}

const char& String::at(size_t pos) const {
    auto traversePoint = head.next;
    while (pos--) {
        traversePoint = traversePoint->next;
    }
    if (traversePoint == nullptr) {
        // throw::out_of_range("Invalid");
    }
    return traversePoint->data;
}

char& String::operator[](size_t pos) {
    return at(pos);
}

const char& String::operator[](size_t pos) const {
    return at(pos);
}

std::ostream& operator<<(std::ostream& os, const String& rhs) {
    for (int i = 0; i < rhs.size(); ++i) {
        cout << rhs.at(i);
    }
    return os;
}

String publicString(const String& lhs, const String& rhs) {   // 双指针       lhs 为短 rhs 为长   lhs 为长 rhs 为短
// 只出现一次
    String result;           // 包含重复字符
    int i = 0, j = 0;           // lhs 做母版
    for (int i = 0; i < lhs.size(); ++i) {
        for (int j = 0; j < rhs.size(); ++j) {
            if (rhs.at(j) == lhs.at(i)) {
                if (result.find(rhs.at(j)) == -1) {
                    result.push_back(rhs.at(j));
                }
            }
        }
    }
    return result;
}

bool palindromicString(const String& val) {
    size_t len = val.size();
    for (int i = 0; i < len / 2; ++i) {
        if (val.at(i) == val.at(len - i - 1)) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

}

<<<<<<< HEAD

=======
>>>>>>> e1d9864b8c472d7ca88b96a6525eed539c1d6fea
// template class String OK
#endif