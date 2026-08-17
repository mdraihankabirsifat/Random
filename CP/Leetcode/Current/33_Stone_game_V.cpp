#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int stoneGameV(vector<int> &stoneValue)
    {
        ll n = stoneValue.size();
        vector<ll> pref(n + 1);
        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < n - i + 1; j++)
            {
                ll k = j + i - 1;
                for (int x = j; x < k; x++)
                {
                    ll l = pref[x + 1] - pref[j];
                    ll r = pref[k + 1] - pref[x + 1];
                    if (l < r)
                    {
                        dp[j][k] = max(dp[j][k], l + dp[j][x]);
                    }
                    else if (l > r)
                    {
                        dp[j][k] = max(dp[j][k], r + dp[x + 1][k]);
                    }
                    else
                    {
                        dp[j][k] = max(dp[j][k], l + max(dp[j][x], dp[x + 1][k]));
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {6, 2, 3, 4, 5, 5};
    Solution sol;
    cout << sol.stoneGameV(v);
    return 0;
}