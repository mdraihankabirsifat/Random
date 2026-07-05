#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tata "\n"

class SegmentTree
{
public:
    vector<ll> tree, arr;

    SegmentTree(ll n)
    {
        tree.assign(4 * n + 5, 0);
        arr.assign(n + 1, 0);
    }

    void build(ll node, ll l, ll r)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(ll node, ll l, ll r, ll idx, ll val)
    {
        if (l == r)
        {
            tree[node] = val;
            arr[idx] = val;
            return;
        }

        ll mid = (l + r) / 2;

        if (idx <= mid)
        {
            update(2 * node, l, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx, val);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || qr < l)
        {
            return 0;
        }

        if (ql <= l && r <= qr)
        {
            return tree[node];
        }

        ll mid = (l + r) / 2;

        ll leftSum = query(2 * node, l, mid, ql, qr);
        ll rightSum = query(2 * node + 1, mid + 1, r, ql, qr);

        return leftSum + rightSum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    SegmentTree seg(n);

    for (ll i = 1; i <= n; i++)
    {
        cin >> seg.arr[i];
    }

    seg.build(1, 1, n);

    while (q--)
    {
        ll type;
        cin >> type;

        if (type == 1)
        {
            ll idx, val;
            cin >> idx >> val;

            seg.update(1, 1, n, idx, val);
        }
        else if (type == 2)
        {
            ll l, r;
            cin >> l >> r;

            cout << seg.query(1, 1, n, l, r) << tata;
        }
    }

    return 0;
}