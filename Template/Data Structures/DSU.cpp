#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

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
        {
            return x;
        }

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

    bool same(ll a, ll b)
    {
        return find(a) == find(b);
    }

    ll size(ll x)
    {
        return sz[find(x)];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n = 10;
    DSU dsu(n);

    dsu.unite(1, 2);
    dsu.unite(2, 3);

    cout << dsu.find(3) << tata;

    if (dsu.same(1, 3))
    {
        cout << "Same component" << tata;
    }
    else
    {
        cout << "Different component" << tata;
    }

    cout << dsu.size(1) << tata;

    return 0;
}