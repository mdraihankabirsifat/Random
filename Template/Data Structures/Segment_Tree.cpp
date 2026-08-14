#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

// =========================================================
// NODE
// Change this depending on the problem
// =========================================================

struct Node
{
    ll val = 0;
};

// =========================================================
// MERGE
// Change this depending on the problem
// =========================================================

Node merge(Node a, Node b)
{
    Node x;
    x.val = a.val + b.val; // range sum
    return x;
}

// =========================================================
// SEGMENT TREE
// =========================================================

class SegmentTree
{
public:
    vector<Node> tree;
    vector<ll> arr;

    SegmentTree(ll n)
    {
        tree.assign(4 * n + 5, Node());
        arr.assign(n + 1, 0);
    }
    // -----------------------------------------------------
    // Build
    // -----------------------------------------------------

    void build(ll node, ll l, ll r)
    {
        if (l == r)
        {
            tree[node].val = arr[l];
            return;
        }
        ll mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // -----------------------------------------------------
    // Point Update
    // arr[idx] = val
    // -----------------------------------------------------

    void update(ll node, ll l, ll r, ll idx, ll val)
    {
        if (l == r)
        {
            arr[idx] = val;
            tree[node].val = val;
            return;
        }
        ll mid = l + (r - l) / 2;
        if (idx <= mid)
        {
            update(2 * node, l, mid, idx, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, r, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    // -----------------------------------------------------
    // Range Query
    // -----------------------------------------------------

    Node query(ll node, ll l, ll r, ll ql, ll qr)
    {
        // Completely outside
        if (r < ql || qr < l)
        {
            return Node(); // neutral node
        }
        // Completely inside
        if (ql <= l && r <= qr)
        {
            return tree[node];
        }
        ll mid = l + (r - l) / 2;
        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(left, right);
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
            Node ans = seg.query(1, 1, n, l, r);
            cout << ans.val << tata;
        }
    }
    return 0;
}