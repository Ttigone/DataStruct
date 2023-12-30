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

    constexpr int I = INT16_MAX;
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
    const int& nodeCount();
    const int& edgeCount();
    const vector<vector<int>>& matrixGraph();
    void degreeOfVertex();

private:
    int nodeCounts;                      // 节点个数
    int edgeCounts;                      // 边数
    vector<vector<int>> edges;          // 邻接矩阵
    vector<MatrixNode<T>> nodeInfo;     // 存放顶点信息
    vector<int> nodeDegree;

};

template<typename T>
MatGraph<T>::MatGraph() : nodeCounts(0), edgeCounts(0) { 
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
    nodeDegree.resize(nodeInfo.size());
    // int edgeNumber = 0;
    while (1) {
        int se = 0;
        int ee = 0;
        int we = 0;
        cin >> se >> ee >> we;
        if (se == -1) {
            break;              // -1 代表输入结束
        }
        edges[se][ee] = we;
        ++edgeCounts;
        ++nodeDegree[se];
        ++nodeDegree[ee];
    }
    nodeCounts = nodeInfo.size();
    for (int i = 0; i < nodeCounts; ++i) {            // 无边赋为 I
        for (int j = 0; j < nodeCounts; ++j) {
            if (i == j) {
                continue;
            } else if (edges[i][j] == 0) {
                edges[i][j] = I;
            } else {
                continue;
            }
        }
    }      
    cout << "number of vertex: " << nodeInfo.size() << endl;
    cout << "number of edge: " << edgeCounts << endl;
    degreeOfVertex();
    for (int i = 0; i < nodeCounts; ++i) {
        for (int j = 0; j < nodeCounts; ++j) {
            edges[i][j] == I ? printf("%-8s ", "INF") : printf("%-8d ", edges[i][j]);
        }
        cout << endl;
    }
}

template<typename T>
MatGraph<T>::~MatGraph() {}

template<typename T>
const int& MatGraph<T>::nodeCount() {
    return nodeCounts;
}

template<typename T>
const int& MatGraph<T>::edgeCount() {
    return edgeCounts;
}

template<typename T>
const vector<vector<int>>& MatGraph<T>::matrixGraph() {
    return edges;
}

template<typename T>
void MatGraph<T>::degreeOfVertex() {
    for (int i = 0; i < nodeInfo.size(); ++i) {
        cout << "Number " << i << " The degree of the vertex: ";
        cout << nodeDegree[i] << endl;
    }
}

}

namespace myGraphWithList {
    using std::vector;
    using std::endl;
    using std::cout;
    using std::cin;
    using std::string;

    constexpr int I = INT16_MAX;
}

namespace myGraphWithList {

struct ListNode {
    ListNode(int i, int j, ListNode* n) : adjvex(i), weight(j), next(n) {}
    int adjvex;            //  边的邻接点编号
    int weight;            //  边的权重
    ListNode *next;        //  指向下一条边的指针
};

template <typename T>
struct PackListNode {
    T info;
    ListNode *firstEdgeNode = nullptr;
};

template <typename T>
class AdjvexGraph {
public:
    AdjvexGraph(const std::vector<std::vector<int>>& matrix, int node, int edge);
    ~AdjvexGraph(void);

public:
    const int& NodeCount(void);
    const int& EdgeCount(void);
    void degreeofVertex(void);
    void showGraph(void);
    void DFS(int v = 0);
    void BFS(int v = 0);
    void Dijkstra(int s = 0, int v = 0);   // s 是原点 // v 是目标点
    void Floyd(int s = 0, int v = 0);

private:
    int nodeCounts;              // 顶点数
    int edgeCounts;              // 边数
    vector<PackListNode<T> *> adjlist;     
    vector<int> nodeDegree;
    vector<int> visited;
    deque<int> queue;
    vector<int> distance; 
    vector<int> preNode;
    priority_queue<pair<int, int>> qt;
    struct edge {
        edge (int vt = 0, int wt = 0) : v(vt), w(wt) {}
        int v, w;
    };
    vector<vector<edge>> keepEdges;

};

template <typename T>
AdjvexGraph<T>::AdjvexGraph(const vector<vector<int>>& matrix, int nodes, int edges) : nodeCounts(nodes), edgeCounts(edges), visited(nodeCounts, 0), preNode(nodeCounts, 0), keepEdges(edges) {
    for (int i = 0; i < nodeCounts; ++i) {
        adjlist.push_back(new PackListNode<T>(i, nullptr));
    }
    nodeDegree.resize(nodeCounts);
    for (int i = 0; i < nodeCounts; ++i) {
        for (int j = nodeCounts - 1; j >= 0; --j) {
            if (matrix[i][j] != 0 && matrix[i][j] != myGraphWithMatrix::I) {
                ListNode *tem = new ListNode(j, matrix[i][j], adjlist[i]->firstEdgeNode);
                adjlist[i]->firstEdgeNode = tem;
                ++nodeDegree[j];
                ++nodeDegree[i];
                // keepEdges[i].v = j;
                // keepEdges[i].w = matrix[i][j];
                keepEdges[i].push_back(edge(j, matrix[i][j]));
            }
        }
    }
}

template <typename T>
AdjvexGraph<T>::~AdjvexGraph(void) {

}

template <typename T>
const int& AdjvexGraph<T>::NodeCount(void) {
    return nodeCounts;
}

template <typename T>
const int& AdjvexGraph<T>::EdgeCount(void) {
    return edgeCounts;   
}

template <typename T>
void AdjvexGraph<T>::degreeofVertex(void) {
    for (int i = 0; i < nodeCounts; ++i) {
        cout << "Number " << i << " The degree of the vertex: ";
        cout << nodeDegree[i] << endl;
    }
}

template <typename T>
void AdjvexGraph<T>::showGraph(void) {
    ListNode *node;
    for (int i = 0; i < nodeCounts; ++i) {
        node = adjlist[i]->firstEdgeNode;
        printf("%-3d: ", i);
        while (node != nullptr) {
            printf("%-d[%-d] ", node->adjvex, node->weight);
            if (node->next != nullptr) {
                cout << " -> ";
            }
            node = node->next;
        }
        cout << endl;
    }
}

template <typename T>
void AdjvexGraph<T>::DFS(int v) {
    ListNode *node = nullptr;
    visited[v] = 1;
    cout << v << ' ';
    node = adjlist[v]->firstEdgeNode;
    while (node != nullptr) {
        if (visited[node->adjvex] == 0) { // 未访问
            DFS(node->adjvex);
        }
        node = node->next;
    }
}

template <typename T>
void AdjvexGraph<T>::BFS(int v) {
    ListNode *node = nullptr;
    visited.assign(nodeCounts, 0);
    printf("%-2d", v);
    visited[v] = 1;
    queue.push_back(v);
    while (!queue.empty()) {
        int t = queue.front();
        queue.pop_front();
        node = adjlist[t]->firstEdgeNode;
        while (node != nullptr) {
            if (visited[node->adjvex] == 0) {
                printf("%-2d", node->adjvex);
                visited[node->adjvex] = 1;
                queue.push_back(node->adjvex);
            }
            node = node->next;
        }
    }
}

template <typename T>
void AdjvexGraph<T>::Dijkstra(int sources, int target) {
    distance.assign(nodeCounts, I);
    visited.assign(nodeCounts, 0);
    distance[sources] = 0;
    qt.push({0, sources});
    while (qt.size()) {
        auto t = qt.top();
        qt.pop();
        int u = t.second;
        if (visited[u]) {
            continue;
        }
        visited[u] = 1;
        for (auto ed : keepEdges[u]) {
            int v = ed.v, w = ed.w;
            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                preNode[v] = u;
                qt.push({-distance[v], v});
            }
        }
    }
    std::function<void(int)> dfs_path; 
    int length = 0;
    vector<int> path;
    dfs_path = [&](int u) -> void {
        ++length;
        if (u == sources) {
            path.push_back(u);   
            return;
        }
        dfs_path(preNode[u]);
        path.push_back(u);
    };

    dfs_path(target);
    cout << sources << " to " << target << " length : " << length;
    cout << " --- shortest path length: ";
    for (auto q : path) {
        cout << q << ' ';
    }
}   

template <typename T>
void AdjvexGraph<T>::Floyd(int sources, int target) {
    distance.assign(nodeCounts, I);
    visited.assign(nodeCounts, 0);
}

}






#endif //DS_GRAPH_HPP
