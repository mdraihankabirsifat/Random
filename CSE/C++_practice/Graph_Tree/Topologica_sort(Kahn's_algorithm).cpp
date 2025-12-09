// Topological Sort using Kahn's Algorithm
#include <vector>
#include <queue>
using namespace std;

// Assumes adjacency list g is defined globally or passed as parameter
// vector<vector<int>> g;

vector<int> topo_sort(int n, vector<vector<int>>& g){
    vector<int> indeg(n+1, 0);
    for(int u=1; u<=n; u++)
        for(int v : g[u])
            indeg[v]++;

    queue<int> q;
    for(int i=1; i<=n; i++)
        if(indeg[i] == 0) q.push(i);

    vector<int> topo;

    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(int v : g[u]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
    
    // Check if topological sort is possible (no cycle)
    // If topo.size() < n, then graph has a cycle
    return topo;
}
