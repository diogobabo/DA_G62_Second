#include <climits>
#include "cenarios.h"

/**
int Cenario2::maxFlow(int s, int t) {
    int nodes, edges;

    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    Graph rGraph(this->g); // Residual graph where rGraph[i][j]
    // indicates residual capacity of edge
    // from i to j (if there is an edge. If
    // rGraph[i][j] is 0, then there is not)

    list<int> parent; // This array is filled by BFS and to
    // store path
    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to
    // sink
    bool flag = true;
    while (flag) {
        parent.clear();
        rGraph.dfshelper(s,parent);
        vector<int> parentVector;
        if(parent.empty()){
            flag = false;
            continue;
        }
        else{
            for(auto val : parent){
                parentVector.push_back(val);
            }
        }
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (edges = t; edges != s; edges = parentVector[edges]) {
            nodes = parentVector[edges];
            auto it = rGraph.nodes[nodes].adj.begin();
            advance(it,edges);
            path_flow = min(path_flow, it->flow);
        }
        // update residual capacities of the edges and
        // reverse edges along the path
        for (edges = t; edges != s; edges = parentVector[edges]) {
            nodes = parentVector[edges];
            rGraph[nodes][edges] -= path_flow;
            rGraph[edges][edges] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}
*/
