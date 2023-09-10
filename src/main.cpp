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

#include "Seqlist/SeqList.hpp"
#include "Linkedlist/DoublyLinkedList.hpp"
#include "Stack/Stack.hpp"
#include "Deque/Deque.hpp"
#include "String/String.hpp"

#include "Stack/Hanoi.hpp"

int main()
{
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    // myseq::SeqList<int> s;
    // s.insert(1, 19);
    // s.traverse();
    // cout << endl;

    // mystack::Stack<int> s1;
    // s1.push(12);
    // s1.traverse();
    // cout << endl;

    // mydoublylist::DoublyLinkedList<int> s2;
    // s2.insert(1, 13);
    // s2.traverse();
    // cout << endl;

    // myqueue::Deque<int> s3;
    // s3.in_queue(13);
    // s3.traverse();

    // myhanoi::hanoi(3, 'a', 'b', 'c');

    myListStack::Stack<int> s;
    s.push(1);
    s.push(2);

    s.push(1);
    s.push(2);
    s.traverse();

    cout << endl;


    

    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "runtime: " << duration.count() << " us" << endl;
    return 0;
}
