#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

const ll INF = 4e18;

// ---------- Edge Structure ----------
struct Edge
{
    ll u, v, w;
};

// ---------- Bellman-Ford ----------
bool bellmanFord(ll n, vector<Edge> &edges, ll source, vector<ll> &dist, vector<ll> &parent, vector<ll> &parentWeight)
{
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    parentWeight.assign(n + 1, 0);

    dist[source] = 0;

    for (ll i = 1; i < n; i++)
    {
        bool changed = false;

        for (Edge e : edges)
        {
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                parentWeight[e.v] = e.w;

                changed = true;
            }
        }

        if (!changed)
            break;
    }

    // Negative cycle detection
    for (Edge e : edges)
    {
        if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w)
        {
            return false;
        }
    }

    return true;
}

// ---------- Print Shortest Path Edges ----------
void printPath(ll source, ll target, vector<ll> &dist, vector<ll> &parent, vector<ll> &parentWeight)
{
    if (dist[target] == INF)
    {
        cout << "No path" << tata;
        return;
    }

    vector<Edge> path;
    ll current = target;

    while (current != source)
    {
        ll previous = parent[current];

        if (previous == -1)
        {
            cout << "No path" << tata;
            return;
        }
        path.pb({previous, current, parentWeight[current]});
        current = previous;
    }

    reverse(path.begin(), path.end());
    cout << "u v w: " << tata;

    for (Edge e : path)
    {
        cout << e.u << " " << e.v << " " << e.w << tata;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, source, target;
    cin >> n >> m;
    vector<Edge> edges;

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w}); // directed edge
    }

    vector<ll> dist,parent,parentWeight;
    bool ok = bellmanFord(n, edges, source, dist, parent, parentWeight);

    if (!ok)
    {
        cout << "NEGATIVE CYCLE" << tata;
    }
    else
    {
        printPath(source, target, dist, parent, parentWeight);
    }
    return 0;
}