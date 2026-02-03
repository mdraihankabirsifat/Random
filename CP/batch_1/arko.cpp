#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y, z) vector<vector<long long>> v((x), vector<long long>((y), (z)))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define db double
#define tata "\n"
using namespace std;
ll MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (char c : s)
    {
        vector<ll> dp1(x + 1, 0);
        for (int j = 0; j <= x; j++)
        {
            if (dp[j] == 0)
            {
                continue;
            }
            dp1[j] = (dp1[j] + dp[j]) % MOD;
            int t = j;
            if (j == x)
            {
                t = x;
            }
            else
            {
                if (c == '(')
                {
                    t = j + 1;
                }
                else
                {
                    t = max(0, j - 1);
                }
                if (t >= x)
                {
                    t = x;
                }
            }
            dp1[t] = (dp1[t] + dp[j]) % MOD;
        }
        dp = dp1;
    }
    cout << dp[x] << endl;
    return 0;
}