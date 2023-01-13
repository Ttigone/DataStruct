#include <iostream>
using namespace std;
int main()
{
    int N, i;
    cin >> N;
    for(i = 1; ; i++){
        N -= i;
        if(N <= 0)
            break;
    } // 最后输出的i 是层数

    system("pause");
    return 0;
}