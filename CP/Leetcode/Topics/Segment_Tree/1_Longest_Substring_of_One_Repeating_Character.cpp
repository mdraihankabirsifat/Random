// https://leetcode.com/problems/longest-substring-of-one-repeating-character/
/*
Problem: Longest Substring of One Repeating Character

After each character replacement query, report the longest substring
whose characters are all identical.
*/
// 2213
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

struct Node

{
    int len = 0, pref = 0, suff = 0, best = 0;
    char left = 0, right = 0;
};

vector<Node> tree;

Node merge(Node a, Node b)
{
    Node x;
    x.len = a.len + b.len;
    x.left = a.left;
    x.right = b.right;
    x.best = max(a.best, b.best);
    x.pref = a.pref;
    if (a.pref == a.len && a.right == b.left)
    {
        x.pref = a.len + b.pref;
    }
    x.suff = b.suff;
    if (b.suff == b.len && a.right == b.left)
    {
        x.suff = a.suff + b.len;
    }
    if (a.right == b.left)
    {
        x.best = max(x.best, a.suff + b.pref);
    }
    return x;
}

void build(int node, int l, int r, string &s)
{
    if (l == r)
    {
        tree[node].left = s[l];
        tree[node].right = s[l];
        tree[node].len = 1;
        tree[node].pref = 1;
        tree[node].suff = 1;
        tree[node].best = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    build(node * 2, l, mid, s);
    build(node * 2 + 1, mid + 1, r, s);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int l, int r, int idx, char c)
{
    if (l == r)
    {
        tree[node].left = c;
        tree[node].right = c;
        tree[node].len = 1;
        tree[node].pref = 1;
        tree[node].suff = 1;
        tree[node].best = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid)
    {
        update(node * 2, l, mid, idx, c);
    }
    else
    {
        update(node * 2 + 1, mid + 1, r, idx, c);
    }
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

class Solution
{
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        int n = s.size();
        int k = queryCharacters.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        vector<int> v;
        for (int i = 0; i < k; i++)
        {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            v.pb(tree[1].best);
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    s1 = "abyzz";
    s2 = "aa";
    vector<int> v = {2, 1};
    Solution sol;
    v = sol.longestRepeating(s1, s2, v);
    out(v);
    return 0;
}
