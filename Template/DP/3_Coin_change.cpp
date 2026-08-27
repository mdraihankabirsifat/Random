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
const ll INF = 4e18;
const ll MOD = 1e9 + 7;

/*
Unlimited coins. Ascending sum allows reusing a coin.
min_coins gives the minimum count; count_ways counts unordered combinations.
Time: O(n * target), Space: O(target).
*/
ll min_coins(vector<ll> &coins, ll target)
{
    vector<ll> dp(target + 1, INF);
    dp[0] = 0;
    for (ll coin : coins)
    {
        for (ll sum = coin; sum <= target; sum++)
        {
            if (dp[sum - coin] != INF)
            {
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
    }
    return dp[target] == INF ? -1 : dp[target];
}

ll count_ways(vector<ll> &coins, ll target)
{
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    for (ll coin : coins)
    {
        for (ll sum = coin; sum <= target; sum++)
        {
            dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
        }
    }
    return dp[target];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, target;
    cin >> n >> target;
    vector<ll> coins(n);
    loop(i, 0, n) cin >> coins[i];
    cout << min_coins(coins, target) << tata;
    cout << count_ways(coins, target) << tata;
    return 0;
}
