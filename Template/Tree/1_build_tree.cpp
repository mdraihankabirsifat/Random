#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

vector<vector<ll>> tree;
vector<ll> parent, depth;

void dfs(ll node, ll par)
{
    parent[node] = par;

    for (ll child : tree[node])
    {
        if (child == par)
            continue;

        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    tree.resize(n + 1);
    parent.resize(n + 1);
    depth.assign(n + 1, 0);

    // Tree has n-1 edges
    loop(i, 0, n - 1)
    {
        ll par, child;
        cin >> par >> child;
        tree[par].pb(child);
        tree[child].pb(par);
    }

    ll root = 1;
    dfs(root, 0);

    return 0;
}