struct Edge
{
    int u, v, w;
};

bool cmp(Edge a, Edge b) { return a.w < b.w; }

class DSU
{
public:
    vector<int> parent, sz;

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

    bool unite(int a, int b)
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

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n, m, u, v, w, ans = 0, edgeCount = 0;
        n = points.size();
        vector<Edge> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                edges.pb(i, j, );
            }
        }

        vector<Edge> edges;
    }
};