#ifndef _ARRAY__HPP_
#define _ARRAY__HPP_

#include <iostream>
#include <vector>

/**
 * @date 2023-11-21
 *
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 *
 * @brief  数组和广义表
 */

namespace myarray {

using std::vector;

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

void theSumAndProductOfSymmetricMatrices(const vector<int>& A, const vector<int>& B) {
    

}


}

#endif
