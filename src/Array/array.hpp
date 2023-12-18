#ifndef _ARRAY__HPP_
#define _ARRAY__HPP_

#include <iostream>
#include <vector>
#include <string>

/**
 * @date 2023-11-21
 *
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 *
 * @brief  数组和广义表
 */

namespace myarray {

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> helix(const int& n);

void theSumAndProductOfSymmetricMatrices();

void showArray(const vector<vector<int>>& array);

}


namespace myarray {

vector<vector<int>> helix(const int& n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int initx = 0, inity = 0;	//每一圈的起始坐标
    int loopNumber = n >> 1;	//一共有多少圈 按圈赋值 n为奇数时需要单独给最中间的位置赋值
    int mid = n >> 1;			//奇数时给最中间的赋值
    int offset = 1;				//换圈时+2 
    int count = 1;				//范围为[1,n*n]
    int i, j;
    while (loopNumber--) {
        i = initx;
        j = inity;
        //给四条边赋值时，每一条边左闭右开，即每一条边的最后一个位置在当前这条边不赋值，避免重复赋值
        //上列从左到右
        for (; j < inity + n - offset; j++) {
            result[i][j] = count++;
        }
        for (; i < initx + n - offset; i++)	{
            result[i][j] = count++;
        }
        for (; j > inity; j--) {
            result[i][j] = count++;
        }
        for (; i > initx; i--) {
            result[i][j] = count++;
        }
        offset += 2;
        initx++;
        inity++;
    }
    if (n % 2) {
        result[mid][mid] = count;
    }      
    return result;
}

void theSumAndProductOfSymmetricMatrices() {
    vector<int> A;
    std::cout << "The A array: ";
    char a;
    std::string s;
    while ((a = cin.get()) != EOF) {
        if (a != ' ' && a != '\n') {
            s.push_back(a);
        } else {
            A.push_back(stoi(s));
            s.clear();
        }
        if (a == '\n') {
            break;
        }
    }

    vector<int> B;
    std::cout << "The B array: ";
    char b;
    std::string s2;
    while ((b = cin.get()) != EOF) {
        if (b != ' ' && b != '\n') {
            s2.push_back(b);
        } else {
            B.push_back(stoi(s2));
            s2.clear();
        }
        if (b == '\n') {
            break;
        }
    }

    int size = A.size();
    int level;
    for (int i = 1; ; ++i) {
        size -= i;
        if (size == 0) {
            level = i;
            break;
        }
    }
    vector<vector<int>> AllA(level, vector<int>(level));
    vector<vector<int>> AllB(level, vector<int>(level));
    int t = 0;
    for (int i = 0; i < level; ++i) { 
        for (int j = 0; j < level; ++j) {
            if (i >= j) {
                AllA[i][j] = A[t];
                AllB[i][j] = B[t];
                AllA[j][i] = AllA[i][j];
                AllB[j][i] = AllB[i][j];
                ++t;
            }
        }
    }

    cout << "Symmetric matrix A: " << endl;
    t = 0;
    for (int i = 0; i < level; ++i) {
        for (int j = 0; j < level; ++j) {
            if (i >= j) {
                cout << A[t++] << ' ';
            }
        }
        cout << endl;
    }


    cout << "Symmetric matrix B: " << endl;
    t = 0;
    for (int i = 0; i < level; ++i) {
        for (int j = 0; j < level; ++j) {
            if (i >= j) {
                cout << B[t++] << ' ';
            }
        }
        cout << endl;
    }

    // 求和
    vector<vector<int>> Sum(level, vector<int>(level));
    for (int i = 0; i < level; ++i) {
        for (int j = 0; j < level; ++j) {
            Sum[i][j] = AllA[i][j] + AllB[i][j];
        }
    }

    vector<vector<int>> Product(level, vector<int>(level));
    for (int i = 0; i < level; ++i) {
        for (int j = 0; j < level; ++j) {
            auto t = AllA[i][j];
            auto t2 = AllB[i][j];
            Product[i][j] = t * t2;
        }
    }

    cout << "Sum: " << endl;
    showArray(Sum);
    cout << "Product: " << endl;
    showArray(Product);
}


void showArray(const vector<vector<int>>& array) {
    for (auto i : array) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}


}

#endif