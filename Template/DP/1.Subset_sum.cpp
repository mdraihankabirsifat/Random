#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

/*
One 0/1 subset with sum = target (non-negative values only).
dp[sum] tells whether sum is possible; parent arrays recover the indices.
Descending sum prevents using the same element more than once.
Time: O(n * target), Space: O(target). Returns false if no subset exists.
*/
bool subset_sum(vector<ll> &v, ll t, vector<ll> &ans)
{
    ll n = v.size();
    vector<bool> dp(t + 1, false);
    vector<ll> Prev_sum(t + 1, -1), idx(t + 1, -1);
    dp[0] = true;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] > t)
        {
            continue;
        }
        for (ll sum = t; sum >= v[i]; sum--)
        {
            if (!dp[sum] && dp[sum - v[i]])
            {
                dp[sum] = true;
                Prev_sum[sum] = sum - v[i];
                idx[sum] = i;
            }
        }
        if (dp[t])
        {
            break;
        }
    }
    if (!dp[t])
    {
        return false;
    }
    while (t > 0)
    {
        ans.pb(idx[t]);
        t = Prev_sum[t];
    }
    reverse(ans.begin(), ans.end());
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> n >> t;
    vector<ll> v(n), ans;
    in(v);
    if (!subset_sum(v, t, ans))
    {
        cout << -1 << tata;
    }
    else
    {
        out(ans);
        cout << tata;
    }
    return 0;
}
