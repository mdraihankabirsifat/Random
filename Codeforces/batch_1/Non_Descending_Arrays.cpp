#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= a[i - 1] && b[i] >= b[i - 1])
            {
                dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
            }
            if (a[i] >= b[i - 1] && b[i] >= a[i - 1])
            {
                dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
            }
            if (b[i] >= a[i - 1] && a[i] >= b[i - 1])
            {
                dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
            }
            if (b[i] >= b[i - 1] && a[i] >= a[i - 1])
            {
                dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
            }
        }
        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;
    }
    return 0;
}