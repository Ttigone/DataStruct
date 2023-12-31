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
    cout << "number of vertex: " << graphWithList.nodeCount() << endl;
    cout << "number of edge: " << graphWithList.edgeCount() << endl;
    graphWithList.showGraph();

    cout << "DFS Traversal: ";
    graphWithList.DFS();
    cout << endl;
    cout << "BFS Traversal: ";
    graphWithList.BFS();
    cout << endl;
    
    cout << "Dijkstra algorithm: " << endl;
    for (int i = 1; i < graphWithList.nodeCount(); ++i) {
        graphWithList.Dijkstra(0, i);
        cout << endl;
    }


    cout << endl;
    cout << "Floyd algorithm: " << endl;
    for (int i = 1; i < graphWithList.nodeCount(); ++i) {
        graphWithList.Floyd(0, i);   
        cout << endl;
    }
        // graphWithList.Floyd(0, 4);   

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