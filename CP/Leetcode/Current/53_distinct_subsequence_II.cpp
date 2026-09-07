// 940
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int distinctSubseqII(string s)
    {
        int n = s.size();
        int MOD = 1E9 + 7;
        vector<int> dp(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) //  v[2]=4
        {
            for (int j = 0; j < i; j++)
            {
                if (s[i] != s[j])
                {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
            ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {};
    string s = "a";
    ll n;
    Solution sol;
    cout << sol.distinctSubseqII(s);
    return 0;
}