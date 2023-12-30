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


#include "Seqlist/SeqList.hpp"
#include "Linkedlist/DoublyLinkedList.hpp"
#include "Linkedlist/LinkedList.hpp"
#include "Stack/Stack.hpp"
#include "Deque/Deque.hpp"
#include "String/String.hpp"
#include "Stack/Hanoi.hpp"
#include "Tree/Binary_Tree.hpp"
#include "array/Array.hpp"
#include "Graph/Graph.hpp"



int main()
{
// #define time

#ifdef time
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif

#ifdef time 
    for (int te = 0; te < 1000; ++te) {
#endif

    myGraphWithMatrix::MatGraph<int> graphWithMatrix;

    myGraphWithList::AdjvexGraph<int> graphWithList(
        graphWithMatrix.matrixGraph(), 
        graphWithMatrix.nodeCount(), 
        graphWithMatrix.edgeCount()
    );
    cout << "number of vertex: " << graphWithList.NodeCount() << endl;
    cout << "number of edge: " << graphWithList.EdgeCount() << endl;
    graphWithList.showGraph();

    cout << "DFS Traversal: ";
    graphWithList.DFS();
    cout << endl;
    cout << "BFS Traversal: ";
    graphWithList.BFS();
    cout << endl;

    for (int i = 1; i < graphWithList.NodeCount(); ++i) {
        graphWithList.Dijkstra(0, i);
        cout << endl;
    }

#ifdef time 
}
#endif

    cout << endl;
#ifdef time
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Run 10000 times: " << duration.count() << " ms" << endl;
#endif
    return 0;

}







// set<int> s;
// s.begin();

// string a = "ABDGCEF";
// string b = "DGBAECF";
//    string a = "DGBAECF";   // in
//    string b = "GDBEFCA";   // post
//    mybinarytree::Tree<char> s;
//    s.getRoot() = s.createTreeIP(a, b, b.size());

//    s.viewTree(s.getRoot());
//
//    cout << s.getRoot();

    // string s;
    // while (getline(cin, s)) {
    //     getline(cin, s);
    //     getline(cin, s);
    //     cout << endl;
    //     auto s1 = s.substr(0, 1);
    //     auto s2 = s.substr(2, s.size() - 2);
    //     long long a = (long long)s1[0] - '0';
    //     long long b{};
    //     for (int i = 0; i < s2.size(); i++) {
    //         b += ((int)s2[i] - '0') * pow(10, s2.size() - i - 1);
    //     }
    //     if (mp[a] < b) {
    //         mp[a] = b;
    //     }
    //     // set1.insert({a, b});
    // // }
    // long long ans {};
    // for (auto i : mp) {
    //     ans += i.second;
    // }
    // cout << ans << endl;
    