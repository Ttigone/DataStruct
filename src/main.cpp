#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// #include "Seqlist/SeqList.hpp"
// #include "Linklist/LinkList.hpp"
#include "Stack/Stack.hpp"
// #include "Deque/Deque.hpp"


int main()
{
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    mystack::Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.traverse();
    cout << endl;

    mystack::Stack<int> s1(s);
    s1.traverse();


    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "runtime: " << duration.count() << " ms" << endl;
    return 0;
}