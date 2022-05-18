
#include "graph.h"
#include <map>
#include <algorithm>

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight, int capacity) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight, capacity});
    if (!hasDir) nodes[dest].adj.push_back({src, weight, capacity});
}

// Depth-First Search: example implementation
int Graph::dfs(int v) {
    int size = 1;
    cout << v << " "; // show node order
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            size += dfs(w);
    }
    return size;
}

// Depth-First Search: example implementation
void Graph::bfs(int v) {
    for (int k=1; k<=n; k++) nodes[k].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

int Graph::outDegree(int v) {
    if(v>nodes.size()-1 || v<1) return -1;
    return (int) nodes.at(v).adj.size();
}

int Graph::connectedComponents() {
    int result=0;
    for(int i=1; i<nodes.size(); i++){
        if(!nodes[i].visited) {
            dfs(i);
            result++;
        }
    }
    return result;
}

int Graph::giantComponent() {
    int max=0;
    for(int i=1; i<nodes.size(); i++){
        if(!nodes[i].visited) {
            int search = dfs(i);
            if(search>max) max = search;
        }
    }
    return max;
}

void Graph::dfshelper(int v, list<int>& order) {
    nodes[v].visited=true;
    for(auto node: nodes[v].adj){
        if(!nodes[node.dest].visited){
            dfshelper(node.dest, order);
        }
    }
    order.push_front(v);
}

list<int> Graph::topologicalSorting() {
    list<int> order;

    for(int i=1; i<nodes.size(); i++){
        if(!nodes[i].visited){
            dfshelper(i, order);
        }
    }
    return order;
}

vector<int> Graph::bfshelper(int a) {
    vector<int> distances(nodes.size(), -1);
    distances[a] = 0;
    for (int v=1; v<=n; v++) nodes[v].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(a);
    nodes[a]. visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        cout << u << " "; // show node order
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                distances[w] = distances[u] + 1;
            }
        }
    }
    return distances;
}

int Graph::distance(int a, int b) {
    return bfshelper(a)[b];
}

int Graph::diameter() {
    if(this->connectedComponents()>1) return -1;
    int diameter = 0;
    for(int i=1; i<nodes.size(); i++){
        vector<int> tmp = bfshelper(i);
        for(int j : tmp){
            if(j>diameter) diameter=j;
        }
    }
    return diameter;
}

bool Graph::hasCycle() {
    return false;
}

int Graph::kruskal() {
    MinHeap<int, int> heap(100, 0);
    DisjointSets<int> disjointSets;
    map<int, pair<int, int>> map;

    int k = 1;
    for(int i=1; i<nodes.size(); ++i){
        disjointSets.makeSet(i);

        Node* u = &nodes[i];
        for(Edge &e: u->adj){
            if(e.dest<i) continue;
            heap.insert(k, e.weight);
            map.insert(make_pair(k, make_pair(i, e.dest)));
            k++;
        }
    }

    int mst = 0;

    while(heap.getSize()>0){
        k = heap.removeMin();
        auto key = map.find(k);
        int origem = key->second.first;
        int destino = key->second.second;

        if(disjointSets.find(origem) != disjointSets.find(destino)){
            for(auto e: nodes[origem].adj) if(e.dest==destino) mst+=e.weight;
            disjointSets.unite(origem, destino);
        }
    }


    return mst;
}

int Graph::prim(int r) {
    MinHeap<int, int> heap((int)nodes.size(), 0);
    auto i = 1;
    for(Node &no: nodes){
        no.distance = INT16_MAX;
        no.parent = 0;
        heap.insert(i, no.distance);
        i++;
    }
    nodes[r].distance=0;
    heap.decreaseKey(r, 0);


    while(heap.getSize()>1){
        i = heap.removeMin();
        cout << i << endl;
        Node* u = &nodes[i];

        for(Edge &e: u->adj){
            if(!heap.hasKey(e.dest)) continue;
            if(e.weight<nodes[e.dest].distance){
                nodes[e.dest].parent=i;
                nodes[e.dest].distance=e.weight;
                heap.decreaseKey(e.dest, e.weight);
            }
        }
    }

    int sum = 0;

    for(const Node& no: nodes){
        if(no.parent==0) continue;
        sum += no.distance;
    }

    return sum;
}
