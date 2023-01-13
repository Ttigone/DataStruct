#include <iostream>
#include <vector>
#define MAXSIZE 20
using namespace std;
typedef int ElemType;
class Sqlist{
public:

};
int main()
{
    ElemType c[] = {1, 2 ,3, 4};
    vector<ElemType>data(c, c + 4);    
    cout << data[0] << endl;
    system("pause");
}