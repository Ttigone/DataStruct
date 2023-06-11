#ifndef _STRING__HPP_
#define _STRING__HPP_ 

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

namespace my_String {
    template <class CharString>
    class String {
        String() {

        }
        ~String() = default;
    private: 

    public:
    /*
    funtion: 将 source 串 复制得到一个串 target
    parameter: target-目标串 source-源串
    return: none
    */
        void Copy(CharString &target, const CharString &source) {

        }

    /*
    funtion: 判断串是否为空
    parametet: none
    return: true is empty false is no empty
    */
        bool Empty() const {

        }
    
    /*
    funtion: 获取字符串个字符个数
    parameter: none
    return: 字符个数
    */
        int Length() const {

        }
    
    /*
    funtion: 链接字符串 
    parameter: target-目标字符串 source-源字符串
    return: none
    */
        void Concat(CharString &target, const CharString &source) {

        }

    /*
    funtion: 求从第 pos 个字符开始长度为 len 的长度
    parameter: s-字符串 pos-位置 len-长度
    return: none
    */
        CharString SubString(const CharString &s, int pos, int len) {

        }

    /*
    funtion: 求取目标串 target 中第 pos 个字符后第一次出现的模式串 pattern
    parameter: target-目标串 pos-位置 pattern-匹配字符串
    return: 获取的位置
    */
        int Index(const CharString &target, const CharString &pattern, int pos = 0) {

        }
    };

}