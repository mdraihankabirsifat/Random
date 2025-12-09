#include <vector>
#include <queue>
using namespace std;

// BFS that returns: farthestNode, distance
// src: starting node, g: adjacency list (1-indexed), n: number of nodes
pair<int, int> farthestNode(int src, vector<vector<int>> &g, int n)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    int far = src;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);

                if (dist[v] > dist[far])
                    far = v;
            }
        }
    }
    return {far, dist[far]};
}

// Compute tree diameter using two BFS approach
// n: number of nodes (1-indexed), g: adjacency list
// Returns the length of the longest path in the tree
int treeDiameter(int n, vector<vector<int>> &g)
{
    auto a = farthestNode(1, g, n).first;
    auto [b, dia] = farthestNode(a, g, n);
    return dia; // diameter length
}
