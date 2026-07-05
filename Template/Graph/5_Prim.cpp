#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

pair<bool, ll> prim(ll n, vector<vector<pair<ll, ll>>> &adj, ll start = 1)
{
    vector<ll> visited(n + 1, 0);

    priority_queue<
        pair<ll, ll>,
        vector<pair<ll, ll>>,
        greater<pair<ll, ll>>>
        pq;

    pq.push({0, start});

    ll mstCost = 0;
    ll takenNodes = 0;

    while (!pq.empty())
    {
        auto [cost, u] = pq.top();
        pq.pop();

        if (visited[u])
        {
            continue;
        }

        visited[u] = 1;
        mstCost += cost;
        takenNodes++;

        for (auto [v, w] : adj[u])
        {
            if (!visited[v])
            {
                pq.push({w, v});
            }
        }
    }

    if (takenNodes != n)
    {
        return {false, mstCost};
    }

    return {true, mstCost};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    auto [ok, mstCost] = prim(n, adj);

    if (!ok)
    {
        cout << "IMPOSSIBLE" << tata;
    }
    else
    {
        cout << mstCost << tata;
    }

    return 0;
}