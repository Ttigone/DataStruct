#include <iostream>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <algorithm>


#include "Seqlist/SeqList.hpp"
// #include "Linklist/LinkList.hpp"
// #include "Stack/Stack.hpp"
// #include "Deque/Deque.hpp"

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    SeqList<int> a(8);
    for (int i = 0; i < 5; ++i) {
        a.insert(i + 1, i);
    }
    a.insert(3, 4);
    a.traverse();
    a.delete_element(4);
    a.traverse();
    return 0;
}
