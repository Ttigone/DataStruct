#include <iostream>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
// #include "Seqlist/SeqList.hpp"
#include <algorithm>
#include "Linklist/LinkList.hpp"
// #include "Stack/Stack.hpp"
// #include "Deque/Deque.hpp"
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<int> s;
    s.push_back(1);
    s.push_back(9);
    s.push_back(2);
    s.push_back(3);
    auto b = std::max_element(s.begin(), s.end());
    auto a = std::distance(s.begin(), b);
    cout << a;
    return 0;
}
