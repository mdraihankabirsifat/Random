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
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (!dp[i])
            {
                for (int j = 1; i + j * j <= n; j++)
                {
                    dp[i + j * j] = true;
                }
                if (dp[n])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    ll n = 4;
    bool p = sol.winnerSquareGame(n);
    if (p)
        yes;
    else
        no;
    return 0;
}