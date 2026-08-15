// https://leetcode.com/problems/stone-game-ii/
/*
Problem: Stone Game II

Two players alternately take piles under the changing 2M limit; return
the maximum number of stones the first player can collect optimally.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))

class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        vector<int> p;
        p = piles;
        ll n = p.size();
        vector<ll> v(n);
        vrr(dp, n, n + 1);
        v[n - 1] = p[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            v[i] = p[i] + v[i + 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i + 2 * j >= n)
                {
                    dp[i][j] = v[i];
                }
                else
                {
                    for (int k = 1; k <= 2 * j; k++)
                    {
                        dp[i][j] = max(dp[i][j], v[i] - dp[i + k][max(j, k)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> v;
    v = {2, 7, 9, 4, 4};
    cout << sol.stoneGameII(v);
    return 0;
}
