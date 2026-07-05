#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Graph
{
public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> visited, dist, parent;

    Graph(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
        visited.assign(n + 1, 0);
        dist.assign(n + 1, -1);
        parent.assign(n + 1, -1);
    }

    void addEdge(ll u, ll v, bool undirected = true)
    {
        adj[u].pb(v);

        if (undirected)
        {
            adj[v].pb(u);
        }
    }

    vector<ll> bfs(ll source)
    {
        vector<ll> order;
        queue<ll> q;

        visited.assign(n + 1, 0);
        dist.assign(n + 1, -1);
        parent.assign(n + 1, -1);

        visited[source] = 1;
        dist[source] = 0;
        q.push(source);

        while (!q.empty())
        {
            ll u = q.front();
            q.pop();

            order.pb(u);

            for (ll v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = 1;
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        return order;
    }

    void dfsHelper(ll u, vector<ll> &order)
    {
        visited[u] = 1;
        order.pb(u);

        for (ll v : adj[u])
        {
            if (!visited[v])
            {
                parent[v] = u;
                dfsHelper(v, order);
            }
        }
    }

    vector<ll> dfs(ll source)
    {
        vector<ll> order;

        visited.assign(n + 1, 0);
        parent.assign(n + 1, -1);

        dfsHelper(source, order);

        return order;
    }

    ll connectedComponents()
    {
        visited.assign(n + 1, 0);

        ll components = 0;

        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                vector<ll> order;
                dfsHelper(i, order);
                components++;
            }
        }

        return components;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v;
    cin >> n >> m;

    Graph g(n);

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<ll> bfsOrder = g.bfs(1);

    for (ll x : bfsOrder)
    {
        cout << x << " ";
    }
    cout << tata;

    vector<ll> dfsOrder = g.dfs(1);

    for (ll x : dfsOrder)
    {
        cout << x << " ";
    }
    cout << tata;

    return 0;
}