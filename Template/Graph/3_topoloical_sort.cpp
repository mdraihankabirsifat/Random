#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class TopologicalSort
{
public:
    ll n;
    vector<vector<ll>> adj;
    vector<ll> indegree;

    TopologicalSort(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
        indegree.assign(n + 1, 0);
    }

    void addEdge(ll u, ll v)
    {
        adj[u].pb(v);
        indegree[v]++;
    }

    vector<ll> kahn()
    {
        queue<ll> q;
        vector<ll> topo;

        for (ll i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            ll u = q.front();
            q.pop();

            topo.pb(u);

            for (ll v : adj[u])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return topo;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v;
    cin >> n >> m;

    TopologicalSort graph(n);

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    vector<ll> topo = graph.kahn();

    if ((ll)topo.size() != n)
    {
        cout << "Cycle Exists" << tata;
    }
    else
    {
        for (ll x : topo)
        {
            cout << x << " ";
        }
        cout << tata;
    }

    return 0;
}