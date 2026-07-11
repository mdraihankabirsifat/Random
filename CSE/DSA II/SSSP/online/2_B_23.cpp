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

// ---------- BFS for Unweighted Graph ----------
vector<ll> bfs(ll n, vector<vector<ll>> &adj, ll source)
{
    vector<ll> dist(n + 1, -1);
    queue<ll> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (ll child : adj[node])
        {
            if (dist[child] == -1)
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }

    return dist;
}

// ---------- Dijkstra with At Most Two Coupons ----------
vector<vector<ll>> dijkstra(ll n, vector<vector<pair<ll, ll>>> &adj, ll source)
{
    vector<vector<ll>> dist(n + 1, vector<ll>(3, INF));

    // {distance, node, couponsUsed}
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

    dist[source][0] = 0;
    pq.push({0, source, 0});

    while (!pq.empty())
    {
        auto [currentDist, node, used] = pq.top();
        pq.pop();

        if (currentDist != dist[node][used])
            continue;

        for (auto child : adj[node])
        {
            ll nextNode = child.first;
            ll weight = child.second;

            // Travel normally
            if (dist[nextNode][used] > dist[node][used] + weight)
            {
                dist[nextNode][used] = dist[node][used] + weight;
                pq.push({dist[nextNode][used], nextNode, used});
            }

            // Use one coupon
            if (used < 2 && dist[nextNode][used + 1] > dist[node][used] + weight / 2)
            {
                dist[nextNode][used + 1] = dist[node][used] + weight / 2;
                pq.push({dist[nextNode][used + 1], nextNode, used + 1});
            }
        }
    }
    return dist;
}

// ---------- Bellman-Ford ----------
bool bellmanFord(ll n, vector<Edge> &edges,ll source, vector<ll> &dist)
{
    dist.assign(n + 1, INF);
    dist[source] = 0;

    for (ll i = 1; i < n; i++)
    {
        bool changed = false;

        for (Edge e : edges)
        {
            if (dist[e.u] != INF &&
                dist[e.v] > dist[e.u] + e.w)
            {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }

        if (!changed)
            break;
    }

    for (Edge e : edges)
    {
        if (dist[e.u] != INF &&
            dist[e.v] > dist[e.u] + e.w)
        {
            return false;
        }
    }

    return true;
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
        adj[u].pb({v, w}); // directed
    }

    vector<vector<ll>> dist = dijkstra(n, adj, 1);

    ll answer = min({dist[n][0], dist[n][1], dist[n][2]});

    if (answer == INF)
        cout << "Not possible" << tata;
    else
        cout << answer << tata;

    return 0;
}