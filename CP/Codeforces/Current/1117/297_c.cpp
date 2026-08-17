#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

vector<vector<ll>> tree;
vector<ll> v, c, a;

void dfs(ll node)
{
    c[node] = v[node];

    for (ll child : tree[node])
    {
        dfs(child);
        c[node] += c[child];
    }
    bool y = false;
    for (ll child : tree[node])
    {
        if (c[child] == 0)
        {
            continue;
        }
        if (!v[node] && !y)
        {
            y = true;
            continue;
        }
        a.pb(child);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n;
        tree.assign(n + 1, {});
        v.assign(n + 1, 0);
        c.assign(n + 1, 0);
        a.clear();
        loop(i, 2, n + 1)
        {
            ll p;
            cin >> p;
            tree[p].pb(i);
        }
        cin >> m;
        loop(i, 0, m)
        {
            ll x;
            cin >> x;
            v[x] = 1;
        }
        dfs(1);
        cout << a.size();
        for (int i = 0; i < a.size(); i++)
        {
            cout << " " << a[i];
        }
        cout << tata;
    }
    return 0;
}