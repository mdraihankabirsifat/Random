#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tata "\n"

ll LCS(string a, string b)
{
    ll n = a.size();
    ll m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << LCS(a, b) << tata;

    return 0;
}