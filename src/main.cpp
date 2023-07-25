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
// #include "Stack/Stack.hpp"
#include "Deque/Deque.hpp"


int main()
{
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    myqueue::Deque<int> d;
    d.in_queue(1);
    d.traverse();
    cout << endl;
    // int n;
    // d.out_queue(n);
    // cout << n;
    // cout << endl;
    // d.traverse();
    d.clear();
    d.traverse();
    d.in_queue(1);
    d.in_queue(2);
    d.in_queue(3);
    d.traverse();

    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "runtime: " << duration.count() << " ms" << endl;
    myqueue::Deque<int> s;
    cout << "yes";
    return 0;
}