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
// #include "Stack/Stack.hpp"
#include "Deque/Deque.hpp"

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    myqueue::Deque<int> s;
    s.in_queue(1);
    s.in_queue(4);
    s.in_queue(2);
    s.in_queue(1);
    s.in_queue(2);
    s.in_queue(6);
    s.in_queue(0);
    s.traverse();
    return 0;
}
