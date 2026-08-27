#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
const ll INF = 4e18;

/*
Minimum path sum from (0,0) to (n-1,m-1), moving right or down.
dp[j] stores the best value for the current column.
Time: O(n * m), Space: O(m).
*/
ll min_path_sum(vector<vector<ll>> &grid)
{
    ll n = grid.size(), m = grid[0].size();
    vector<ll> dp(m, INF);
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            if (i == 0 && j == 0)
            {
                dp[j] = grid[i][j];
                continue;
            }
            ll from_top = dp[j];
            ll from_left = (j > 0 ? dp[j - 1] : INF);
            dp[j] = min(from_top, from_left) + grid[i][j];
        }
    }
    return dp[m - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vrr(grid, n, m);
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            cin >> grid[i][j];
        }
    }
    cout << min_path_sum(grid) << tata;
    return 0;
}
