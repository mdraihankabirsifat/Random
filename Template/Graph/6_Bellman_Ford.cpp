#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

const ll INF = 1e18;

struct Edge
{
    ll u, v, w;
};

bool bellmanFord(ll n, vector<Edge> &edges, ll src, vector<ll> &dist)
{
    dist.assign(n + 1, INF);
    dist[src] = 0;

    for (ll i = 1; i < n; i++)
    {
        bool updated = false;

        for (Edge e : edges)
        {
            if (dist[e.u] == INF)
            {
                continue;
            }

            if (dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }

        if (!updated)
        {
            break;
        }
    }

    for (Edge e : edges)
    {
        if (dist[e.u] == INF)
        {
            continue;
        }

        if (dist[e.u] + e.w < dist[e.v])
        {
            return false; // negative cycle found
        }
    }

    return true; // no negative cycle
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        edges.pb({u, v, w});
    }

    ll src;
    cin >> src;

    vector<ll> dist;

    bool ok = bellmanFord(n, edges, src, dist);

    if (!ok)
    {
        cout << "Negative Cycle Found" << tata;
        return 0;
    }

    for (ll i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }

    cout << tata;

    return 0;
}