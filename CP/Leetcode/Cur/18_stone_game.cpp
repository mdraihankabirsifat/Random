#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define rsort(a) sort(a.begin(), a.end(), greater<>())
#define ulta(a) reverse(a.begin(), a.end())
#define mucho(a, j) a.erase(a.begin() + j)
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

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