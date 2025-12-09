#include <vector>
#include <iostream>
using namespace std;

// Build an undirected graph
// n: number of nodes (1-indexed), m: number of edges
// Returns adjacency list with g[0] unused
vector<vector<int>> buildGraph(int n, int m)
{
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}

// Build a directed graph
// n: number of nodes (1-indexed), m: number of edges
// Returns adjacency list with g[0] unused
vector<vector<int>> buildDirectedGraph(int n, int m)
{
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    return g;
}
