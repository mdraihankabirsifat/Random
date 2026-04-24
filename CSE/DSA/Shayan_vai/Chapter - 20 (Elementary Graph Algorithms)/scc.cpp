#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
vector<vector<int>> adj(N);
vector<int> color(N);
vector<int> par(N);
vector<int> start(N);
vector<int> finish(N);
int cur_time = 0;
int n;
vector<int> ans;

void dfs()
{
    for (int i = 1; i <= n; i++)
    {
        color[i] = 0;
        par[i] = -1;
    }
    cur_time = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
            dfs_visit(i);
    }
}

void dfs_visit(int node)
{
    cur_time = cur_time + 1;
    start[node] = cur_time;
    color[node] = 1;
    for (auto ele : adj[node])
    {
        if (!color[ele])
        {
            dfs_visit(ele);
        }
    }
    color[node] = 3;
    finish[node] = ++cur_time;
    ans.push_back(node);
}

vector<vector<int>> adj1(N);
vector<int> vis(N);

void dfs1(int node, vector<vector<int>> &adj1, vector<int> &vis, vector<vector<int>> &sccs)
{
    vis[node] = 1;
    sccs.back().push_back(node);
    for (auto ele : adj1[node])
    {
        if (!vis[ele])
            dfs1(ele, adj1, vis, sccs);
    }
}

void scc()
{
    reverse(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++)
    {
        for (auto ele : adj[i])
        {
            adj1[ele].push_back(i);
        }
    }
    vector<vector<int>> sccs;
    for (auto ele : ans)
    {
        if (!vis[ele])
        {
            sccs.push_back({});
            dfs1(ele, adj1, vis, sccs);
        }
    }
}
