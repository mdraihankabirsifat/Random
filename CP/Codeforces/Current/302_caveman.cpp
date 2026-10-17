
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)

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
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll u, v, n, m;
        cin >> n >> m;
        Graph g(n);
        for (ll i = 0; i < m; i++)
        {
            cin >> u >> v;
            g.addEdge(u, v);
        }
        ll l = 0, mx = 0, alada = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll d = g.adj[i].size();
            if (d == 0)
            {
                alada = 1;
            }
            if (d == 1)
            {
                l++;
            }
            mx = max(mx, d);
        }
        if (alada)
        {
            cout << "Brain Melt" << tata;
        }
        else if (mx == n - 1 && l == n - 1)
        {
            cout << 2 << tata;
        }
        else
        {
            cout << "Many" << tata;
        }
    }
    return 0;
}