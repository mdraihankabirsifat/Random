
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
    vector<ll> visited;

    Graph(ll n)
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

    void dfs(ll u, vector<ll> &component)
    {
        visited[u] = 1;
        component.pb(u);

        for (ll v : adj[u])
        {
            if (!visited[v])
                dfs(v, component);
        }
    }

    vector<vector<ll>> connectedComponents()
    {
        visited.assign(n + 1, 0);
        vector<vector<ll>> components;

        for (ll i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                vector<ll> component;
                dfs(i, component);
                components.pb(component);
            }
        }

        return components;
    }

    // Independent Cycle Detection
    bool dfsCycle(ll u, ll parent, vector<ll> &vis)
    {
        vis[u] = 1;
        bool skippedParent = false;

        for (ll v : adj[u])
        {
            if (v == parent && !skippedParent)
            {
                skippedParent = true;
                continue;
            }

            if (vis[v])
                return true;

            if (dfsCycle(v, u, vis))
                return true;
        }

        return false;
    }

    bool hasCycle()
    {
        vector<ll> vis(n + 1, 0);

        for (ll i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (dfsCycle(i, -1, vis))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, u, v;
        cin >> n >> m;

        Graph g(n);

        for (ll i = 0; i < m; i++)
        {
            cin >> u >> v;
            g.addEdge(u, v);
        }

        // Independent cycle detection
        if (g.hasCycle())
            cout << "Cycle Found" << tata;
        else
            cout << "No Cycle" << tata;

        // Original graph remains unchanged
        vector<vector<ll>> components = g.connectedComponents();

        cout << "Components: " << components.size() << tata;

        for (auto component : components)
        {
            for (ll x : component)
                cout << x << " ";
            cout << tata;
        }
    }

    return 0;
}