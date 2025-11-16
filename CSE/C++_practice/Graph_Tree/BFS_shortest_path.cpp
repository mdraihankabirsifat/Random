#include <vector>
#include <queue>
using namespace std;

// BFS returns distance array from source
// g: adjacency list (1-indexed), n: number of nodes (nodes are numbered 1 to n)
// Returns: dist[i] = shortest distance from src to node i, or -1 if unreachable
// dist[0] is unused for 1-indexed graphs
vector<int> BFS(int src, vector<vector<int>> &g, int n)
{
    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (dist[v] == -1)
            {                          // not visited yet
                dist[v] = dist[u] + 1; // update distance
                q.push(v);
            }
        }
    }
    return dist;
}
