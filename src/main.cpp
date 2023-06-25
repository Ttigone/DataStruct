#include <iostream>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <algorithm>


// #include "Seqlist/SeqList.hpp"
// #include "Linklist/LinkList.hpp"
#include "Stack/Stack.hpp"
// #include "Deque/Deque.hpp"

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    my_stack::Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(9);
    s.push(2);
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(1);
    s.push(0);
    s.push(8);
    s.traverse();
    return 0;
}
