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
Strictly increasing LIS with reconstruction.
Use upper_bound instead of lower_bound for non-decreasing LIS.
Time: O(n log n), Space: O(n). Returns indices.
*/
vector<ll> lis_indices(vector<ll> &v)
{
    ll n = v.size();
    vector<ll> tail_value, tail_index, previous_index(n, -1);
    loop(i, 0, n)
    {
        ll pos = lower_bound(tail_value.begin(), tail_value.end(), v[i]) - tail_value.begin();
        if (pos == (ll)tail_value.size())
        {
            tail_value.pb(v[i]);
            tail_index.pb(i);
        }
        else
        {
            tail_value[pos] = v[i];
            tail_index[pos] = i;
        }
        if (pos > 0)
        {
            previous_index[i] = tail_index[pos - 1];
        }
    }
    vector<ll> ans;
    ll cur = tail_index.back();
    while (cur != -1)
    {
        ans.pb(cur);
        cur = previous_index[cur];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> v(n);
    loop(i, 0, n)
    {
        cin >> v[i];
    }
    if (n == 0)
    {
        cout << 0 << tata;
        return 0;
    }
    vector<ll> indices = lis_indices(v);
    cout << indices.size() << tata;
    ll lis_size = indices.size();
    loop(i, 0, lis_size)
    {
        cout << indices[i] << " ";
    }
    cout << tata;
    for (ll index : indices)
    {
        cout << v[index] << " ";
    }
    cout << tata;
    return 0;
}
