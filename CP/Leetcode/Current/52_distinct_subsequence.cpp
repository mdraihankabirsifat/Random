#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        ll m = s.size(), n = t.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            ll d = 1;
            for (int j = 1; j <= n; j++)
            {
                ll cur = dp[j], nisi = 0, ney_nai = 0;
                if (s[i - 1] == t[j - 1])
                {
                    nisi = d;
                }
                ney_nai = cur;
                dp[j] = nisi + ney_nai;
                d = cur;
            }
        }
        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {};
    string s = "";
    ll n;
    Solution sol;
    // cout << sol.;
    return 0;
}