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
string digits;
ll target_sum;
ll dp[20][172];

/*
Counts numbers in [0, x] whose digit sum equals target_sum.
State: position, current sum, and whether the prefix is tight.
For a range [l,r], use count_upto(r) - count_upto(l-1).
*/
ll digit_dp(ll pos, ll sum, bool tight)
{
    if (sum > target_sum)
    {
        return 0;
    }
    if (pos == (ll)digits.size())
    {
        return sum == target_sum;
    }
    if (!tight && dp[pos][sum] != -1)
    {
        return dp[pos][sum];
    }
    ll limit = tight ? digits[pos] - '0' : 9;
    ll ans = 0;
    for (ll digit = 0; digit <= limit; digit++)
    {
        ans += digit_dp(pos + 1, sum + digit, tight && digit == limit);
    }
    if (!tight)
    {
        dp[pos][sum] = ans;
    }
    return ans;
}

ll count_upto(ll x, ll wanted_sum)
{
    if (x < 0 || wanted_sum < 0 || wanted_sum > 171)
    {
        return 0;
    }
    digits = to_string(x);
    target_sum = wanted_sum;
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 0, true);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r, wanted_sum;
    cin >> l >> r >> wanted_sum;
    cout << count_upto(r, wanted_sum) - count_upto(l - 1, wanted_sum) << tata;
    return 0;
}
