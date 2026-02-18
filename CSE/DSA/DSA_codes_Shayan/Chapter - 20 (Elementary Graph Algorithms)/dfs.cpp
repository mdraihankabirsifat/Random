#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
vector<vector<int>> adj(N);
vector<int> vis(N);

void dfs(int node)
{
    vis[node] = 1;
    for (auto ele : adj[node])
    {
        if (!vis[ele])
        {
            dfs(ele);
        }
    }
}