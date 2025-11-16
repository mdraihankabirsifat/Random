#include <vector>
using namespace std;

// Global variables for tree/graph DFS
vector<int> depth, parent;
vector<vector<int>> g; // adjacency list

// DFS to compute parent[] and depth[]
// u: current node, p: parent node
// Initialize: depth[root] = 0 before calling DFS(root, -1)
void DFS(int u, int p)
{
    parent[u] = p;
    for (int v : g[u])
    {
        if (v == p)
            continue; // ignore back edge to parent
        depth[v] = depth[u] + 1;
        DFS(v, u);
    }
}