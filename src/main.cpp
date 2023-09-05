#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <array>
#include <algorithm>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <locale>
#include <functional>
#include <unordered_map>
#include <memory>
#include <numeric>
#include <utility>

#include <stdio.h>

using namespace std;


using namespace std::placeholders;

// #include "Seqlist/SeqList.hpp"
// #include "Linkedlist/DoublyLinkedList.hpp"
// #include "Stack/Stack.hpp"
// #include "Deque/Deque.hpp"
// #include "String/String.hpp"

shared_ptr<int> f(int i) {
    return make_shared<int>(i);
}

int main()
{
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);



    int r = 32;
    int &&i = std::move(r);
    cout << i << endl;
    i = 22;
    cout << i << endl;

    r = 24;
    cout << i << endl;

    int &&s = 31;

    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "runtime: " << duration.count() << " ms" << endl;
    return 0;
}
