#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define V vector<vector<ll>>
const ll INF = LLONG_MAX;

void addEdge(ll u, ll v, ll c, V &adj, V &capacity)
{
    adj[u].pb(v);
    adj[v].pb(u);        // reverse residual edge
    capacity[u][v] += c; // handles parallel edges
}

ll bfs(ll source, ll sink, V &adj, V &capacity, vector<ll> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<ll, ll>> q;
    q.push({source, INF});

    while (!q.empty())
    {
        auto [node, flow] = q.front();
        q.pop();

        for (ll child : adj[node])
        {
            if (parent[child] == -1 && capacity[node][child] > 0)
            {
                parent[child] = node;
                ll newFlow = min(flow, capacity[node][child]);
                if (child == sink)
                    return newFlow;
                q.push({child, newFlow});
            }
        }
    }
    return 0;
}

// Edmonds-Karp = Ford-Fulkerson using BFS, O(VE^2).
ll edmondsKarp(ll source, ll sink, V &adj, V &capacity)
{
    ll maxFlow = 0, pathFlow;
    vector<ll> parent(adj.size());

    while ((pathFlow = bfs(source, sink, adj, capacity, parent)) > 0)
    {
        maxFlow += pathFlow;
        for (ll node = sink; node != source; node = parent[node])
        {
            ll previous = parent[node];
            capacity[previous][node] -= pathFlow;
            capacity[node][previous] += pathFlow;
        }
    }
    return maxFlow;
}

struct MatchingResult
{
    ll size;
    vector<ll> leftMatch, rightMatch;
};

// Left side: 0...L-1, right side: 0...R-1.
MatchingResult maxBipartiteMatching(ll L, ll R,const vector<pair<ll, ll>> &edges)
{
    ll source = 0, leftStart = 1, rightStart = leftStart + L;
    ll sink = rightStart + R, totalNodes = sink + 1;
    V adj(totalNodes), capacity(totalNodes, vector<ll>(totalNodes, 0));

    for (ll u = 0; u < L; u++)
        addEdge(source, leftStart + u, 1, adj, capacity);
    for (ll v = 0; v < R; v++)
        addEdge(rightStart + v, sink, 1, adj, capacity);
    for (auto [u, v] : edges)
        addEdge(leftStart + u, rightStart + v, 1, adj, capacity);

    MatchingResult ans;
    ans.size = edmondsKarp(source, sink, adj, capacity);
    ans.leftMatch.assign(L, -1);
    ans.rightMatch.assign(R, -1);

    for (auto [u, v] : edges)
    {
        if (capacity[leftStart + u][rightStart + v] == 0)
        {
            ans.leftMatch[u] = v;
            ans.rightMatch[v] = u;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // General maximum flow: n m, then m edges (u, v, capacity).
    // Nodes are 0...n-1; source = 0, sink = n-1.
    ll n, m;
    cin >> n >> m;
    V adj(n), capacity(n, vector<ll>(n, 0));

    while (m--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        addEdge(u, v, c, adj, capacity);
    }
    cout << edmondsKarp(0, n - 1, adj, capacity) << tata;
    return 0;
}

/*
BIPARTITE USE:
    MatchingResult ans = maxBipartiteMatching(L, R, edges);
    cout << ans.size << tata;

DAG MINIMUM PATH COVER (offline airline pattern):
    Use L = R = N and add (u, v) for every valid DAG edge u -> v.
    minimumPathCover = N - ans.size
    ans.leftMatch[u]  = next vertex after u
    ans.rightMatch[v] = previous vertex before v
    Start a route at every v for which ans.rightMatch[v] == -1,
    then repeatedly follow ans.leftMatch[v] until it becomes -1.
*/
