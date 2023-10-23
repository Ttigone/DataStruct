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



int main()
{
    cout << __TIME__ << endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

// for (int s = 0; s < 10000; ++s) {

    // mylist::LinkList<int> list;
    // list.insert(1, 2);
    // list.insert(2, 8);
    // list.insert(3, 16);
    // list.insert(4, 4);
    // cout << "list 链表元素为：";
    // list.traverse();
    // cout << endl;

    // int a[] = {1, 23, 12, 2, 9, 5};
    // mylist::LinkList<int> list2(a, sizeof(a) / sizeof(int));
    // cout << "list2 链表元素为：";
    // list2.traverse();
    // cout << endl;

    // mylist::LinkList<int> list3(mylist::merge(list, list2));
    // cout << "合并之后的链表 list3 元素为：";
    // list3.traverse();
    // cout << endl;

    // cout << "list 链表排序后元素为：";
    // mylist::sort(list).traverse();
    // cout << endl;

    // cout << "list 和 list2 的交集为：";
    // mylist::interSect(list, list2).traverse();
    // cout << endl;

    // cout << "list 和 list3 的差集为：";
    // mylist::subs(list, list3).traverse();
    // cout << endl;
    
    myqueue::Deque<int> queue1;
    queue1.push_back(1);
    queue1.push_back(2);
    queue1.push_back(5);
    queue1.push_back(8);
    queue1.traverse();   


    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Run 10000 times: " << duration.count() << " ms" << endl;
    return 0;
}
