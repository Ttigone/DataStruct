#include <iostream>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
#include <algorithm>

class MyCompare {
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};
void test()
{
    set<int> s;
    s.insert(20);
    s.insert(40);
    s.insert(50);
    s.insert(30);
    s.insert(10);
    set<int, MyCompare>s2;  //·Âº¯Êı  ÖØÔØĞ¡À¨ºÅ()
    s2.insert(40);
    s2.insert(50);
    s2.insert(20);
    s2.insert(30);
    s2.insert(10);
    for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;


}
int main()
{
    // binary_search
    // test();
    vector<string> msg {"hello", "C++", "World"};
    for(const string& word : msg){
        cout << word << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
}