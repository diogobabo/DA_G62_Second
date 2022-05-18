#ifndef DA_T6_G62_GRAPH_H
#define DA_T6_G62_GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include "minHeap.h"
#include "disjointSets.h"

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
        int capacity;
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        int distance;
        int parent;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    explicit Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1, int capacity = 1);

    // Depth-First Search: example implementation
    int dfs(int v);

    // Breadth-First Search: example implementation
    void bfs(int v);

    // ----- Functions -----
    int outDegree(int v);
    int connectedComponents();
    int giantComponent();
    void dfshelper(int v, list<int>& order);
    list<int> topologicalSorting();
    vector<int> bfshelper(int a);
    int distance(int a, int b);
    int diameter();
    bool hasCycle();
    int prim(int v);
    int kruskal();

    int printDirections() const;
};

#endif //DA_T6_G62_GRAPH_H
