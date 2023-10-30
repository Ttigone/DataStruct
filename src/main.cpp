//#include "Seqlist/SeqList.hpp"
// #include "Linkedlist/DoublyLinkedList.hpp"
//#include "Linkedlist/LinkedList.hpp"
//#include "Stack/Stack.hpp"
#include "Deque/Deque.hpp"
//#include "String/String.hpp"
//#include "Stack/Hanoi.hpp"
//#include "Tree/Binary_Tree.hpp"
#include <bits/stdc++.h>

using namespace std;





int main()
{
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    myqueue::Deque<int> deque;

    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_back(4);

    deque.traverse();
    cout << endl;

    deque.clear();
    deque.traverse();
    cout << endl;

    deque.push_back(1);
    deque.traverse();
    cout << endl;


    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Run 10000 times: " << duration.count() << " ms" << endl;
    return 0;
}





//     for (int i = 0; i < 1; ++i) {
//         mybinarytree::Tree<char> tree("A(B(D(,G)),C(E,F))");
//         tree.viewTree(tree.getRoot());
//         cout << endl;
//         // cout << tree.treeHeight(tree.getRoot());
//         tree.inOrder(tree.getRoot());
//         cout << endl;
//         tree.postOrder(tree.getRoot());
//         cout << endl;
//         tree.preOrder(tree.getRoot());
//         cout << endl;
//         cout << tree.nodeCount(tree.getRoot()) << endl;
//
//         tree.viewLeafL(tree.getRoot());
//         cout << endl;
//         tree.viewLeafH(tree.getRoot());
//         cout << endl;
//     }


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
    