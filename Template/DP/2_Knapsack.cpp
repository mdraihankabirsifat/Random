#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

/*
0/1 Knapsack: each item can be taken once.
Descending capacity prevents taking an item again.
Time: O(n * capacity), Space: O(capacity).
*/
ll knapsack(vector<ll> &weight, vector<ll> &value, ll capacity)
{
    ll n = weight.size();
    vector<ll> dp(capacity + 1, 0);
    loop(i, 0, n)
    {
        for (ll w = capacity; w >= weight[i]; w--)
        {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[capacity];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, capacity;
    cin >> n >> capacity;
    vector<ll> weight(n), value(n);
    loop(i, 0, n)
    {
        cin >> weight[i] >> value[i];
    }
    cout << knapsack(weight, value, capacity) << tata;
    return 0;
}
