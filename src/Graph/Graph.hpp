#ifndef DS_GRAPH_HPP
#define DS_GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>

/**
 * @date 2023-12-12
 *
 * @author C3H3_Ttigone
 * @Contact caicaishaoshan@gmail.com
 *
 * @brief 图
 */

namespace myGraphWithMatrix {
    using std::vector;
    using std::endl;
    using std::cout;
    using std::cin;
    using std::string;

}

namespace myGraphWithMatrix {

template<typename T>
struct MatrixNode {
    MatrixNode(void) : info(T()), num(0) { }
    MatrixNode(int n, T i) : num(n), info(i) { }
    int num;                                    // 顶点编号
    T info;                                     // 顶点信息
};


template<typename T>
class MatGraph {
public:
    MatGraph(void);
    ~MatGraph(void);

public:
    int showNodeCount();
    int showEdgeCount();
    void showDegreeOfVertex();

private:
    int nodeCount;                      // 节点个数
    int edgeCount;                      // 边数
   vector<vector<int>> edges;          // 邻接矩阵
    vector<MatrixNode<T>> nodeInfo;     // 存放顶点信息

};

template<typename T>
MatGraph<T>::MatGraph() : nodeCount(0), edgeCount(0) { 
    cout << "Input vertex information: ";
    char tem;
    string s;
    while ((tem = cin.get()) != EOF) {
        if (tem != ' ' && tem != '\n') {
            s.push_back(tem);
        } else {
            nodeInfo.push_back(MatrixNode<int>(stoi(s), 0));
            s.clear();
        }
        if (tem == '\n') {
            break;
        }
    }
    edges.resize(nodeInfo.size(), vector<int>(nodeInfo.size(), 0));
    cout << "Input edges and weights: " << endl;
    vector<int> nodeDegree(nodeInfo.size());
    int edgeNumber = 0;
    while (1) {
        int se = 0;
        int ee = 0;
        int we = 0;
        cin >> se >> ee >> we;
        if (se == -1) {
            break;              // -1 代表输入结束
        }
        edges[se][ee] = we;
        ++edgeNumber;
        ++nodeDegree[se];
        ++nodeDegree[ee];
    }
    cout << "number of vertex: " << nodeInfo.size() << endl;
    cout << "number of edge: " << edgeNumber << endl;
    for (int i = 0; i < nodeInfo.size(); ++i) {
        cout << "Number " << i << " The degree of the vertex: ";
        cout << nodeDegree[i] << endl;
    }
}






template<typename T>
MatGraph<T>::~MatGraph() {}



template<typename T>
int MatGraph<T>::showNodeCount() {
    return nodeCount;
}

template<typename T>
int MatGraph<T>::showEdgeCount() {
    return edgeCount;
}

template<typename T>
void MatGraph<T>::showDegreeOfVertex() {

}

}


namespace myGraphWithList {
    using std::vector;
    using std::endl;
    using std::cout;
    using std::cin;
    using std::string;
}

namespace myGraphWithList {

struct ListNode {
    int adjvex;            //  边的邻接点编号
    int weight;            //  边的权重
    ListNode *next;        //  指向下一条边的指针
};

template <typename T>
struct PackListNode {
    T info;
    ListNode *firstEdgeNode;
};


}






#endif //DS_GRAPH_HPP
