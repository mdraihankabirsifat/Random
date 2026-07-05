#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

struct Edge
{
    ll to, id;
};

vector<ll> tin, low, vis;
vector<pair<ll, ll>> bridges;
ll timer = 0;

void dfsBridge(ll node, ll parentEdge, vector<vector<Edge>> &graph)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (Edge e : graph[node])
    {
        ll child = e.to;
        ll edgeId = e.id;

        if (edgeId == parentEdge)
        {
            continue;
        }

        if (vis[child])
        {
            low[node] = min(low[node], tin[child]);
        }
        else
        {
            dfsBridge(child, edgeId, graph);

            low[node] = min(low[node], low[child]);

            if (low[child] > tin[node])
            {
                bridges.pb({node, child});
            }
        }
    }
}

vector<pair<ll, ll>> findBridges(ll n, vector<vector<Edge>> &graph)
{
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    vis.assign(n + 1, 0);

    bridges.clear();
    timer = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfsBridge(i, -1, graph);
        }
    }

    return bridges;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;

        graph[u].pb({v, i});
        graph[v].pb({u, i});
    }

    vector<pair<ll, ll>> ans = findBridges(n, graph);

    cout << ans.size() << tata;

    for (auto [u, v] : ans)
    {
        cout << u << " " << v << tata;
    }

    return 0;
}