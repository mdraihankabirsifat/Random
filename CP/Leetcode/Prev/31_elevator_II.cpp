#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define sajai(x) sort(x.begin(), x.end())

vector<int> a;
vector<vector<vector<ll>>> dp;
int m, N;

ll solve(int l, int r, int side)
{
    if (l == 0 && r == N - 1)
    {
        return 0;
    }
    ll &ans = dp[l][r][side];
    if (ans != -1)
    {
        return ans;
    }
    ans = LLONG_MAX / 4;
    ll rem = m - (r - l);
    int cur;
    if (side == 0)
    {
        cur = a[l];
    }
    else
    {
        cur = a[r];
    }
    if (l > 0)
    {
        ll dis = cur - a[l - 1];
        ans = min(ans, rem * dis + solve(l - 1, r, 0));
    }
    if (r + 1 < N)
    {
        ll dis = a[r + 1] - cur;
        ans = min(ans, rem * dis + solve(l, r + 1, 1));
    }
    return ans;
}

class Solution
{
public:
    long long elevatorRequests(int n, int start, vector<int> &requests)
    {
        a.clear();
        dp.clear();
        for (int x : requests)
        {
            if (x != start)
            {
                a.pb(x);
            }
        }
        m = a.size();
        if (m == 0)
        {
            return 0;
        }
        a.pb(start);
        sajai(a);
        N = a.size();
        int p = lower_bound(a.begin(), a.end(), start) - a.begin();
        dp.assign(N, vector<vector<ll>>(N, vector<ll>(2, -1)));
        return solve(p, p, 0);
    }
};