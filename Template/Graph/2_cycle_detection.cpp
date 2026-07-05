#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class UndirectedCycle
{
public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> visited;

    UndirectedCycle(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
        visited.assign(n + 1, 0);
    }

    void addEdge(ll u, ll v)
    {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool dfs(ll u, ll parent)
    {
        visited[u] = 1;

        for (ll v : adj[u])
        {
            if (!visited[v])
            {
                if (dfs(v, u))
                {
                    return true;
                }
            }
            else if (v != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool hasCycle()
    {
        visited.assign(n + 1, 0);

        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

class DirectedCycle
{
public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> color;

    DirectedCycle(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
        color.assign(n + 1, 0);
    }

    void addEdge(ll u, ll v)
    {
        adj[u].pb(v);
    }

    bool dfs(ll u)
    {
        color[u] = 1;

        for (ll v : adj[u])
        {
            if (color[v] == 0)
            {
                if (dfs(v))
                {
                    return true;
                }
            }
            else if (color[v] == 1)
            {
                return true;
            }
        }

        color[u] = 2;
        return false;
    }

    bool hasCycle()
    {
        color.assign(n + 1, 0);

        for (ll i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                if (dfs(i))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v;
    cin >> n >> m;

    UndirectedCycle graph(n);

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.hasCycle())
    {
        cout << "Cycle Found" << tata;
    }
    else
    {
        cout << "No Cycle" << tata;
    }

    return 0;
}