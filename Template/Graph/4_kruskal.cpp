#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

struct Edge
{
    ll u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

class DSU
{
public:
    vector<ll> parent, sz;

    DSU(ll n)
    {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (ll i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    ll find(ll x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(ll a, ll b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
        {
            return false;
        }

        if (sz[a] < sz[b])
        {
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, u, v, w, ans = 0, edgeCount = 0;
    cin >> n >> m;

    vector<Edge> edges;

    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);

    for (Edge e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            ans += e.w;
            edgeCount++;

            if (edgeCount == n - 1)
            {
                break;
            }
        }
    }

    if (edgeCount == n - 1)
    {
        cout << ans << tata;
    }
    else
    {
        cout << "IMPOSSIBLE" << tata;
    }

    return 0;
}