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
Minimum Hamiltonian cycle starting and ending at node 0; use for n <= 20.
dp[mask][u] = minimum cost to visit mask and finish at u.
Time: O(2^n * n^2), Space: O(2^n * n).
*/
ll tsp(vector<vector<ll>> &cost)
{
    ll n = cost.size();
    ll total_masks = 1LL << n;
    vector<vector<ll>> dp(total_masks, vector<ll>(n, INF));
    dp[1][0] = 0;
    for (ll mask = 1; mask < total_masks; mask++)
    {
        if (!(mask & 1LL))
        {
            continue;
        }
        loop(u, 0, n)
        {
            if (!(mask & (1LL << u)) || dp[mask][u] == INF)
            {
                continue;
            }
            loop(v, 0, n)
            {
                if (mask & (1LL << v))
                {
                    continue;
                }
                ll next_mask = mask | (1LL << v);
                dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }
    ll ans = INF;
    ll full_mask = total_masks - 1;
    loop(u, 0, n)
    {
        ans = min(ans, dp[full_mask][u] + cost[u][0]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vrr(cost, n, n);
    loop(i, 0, n)
    {
        loop(j, 0, n)
        {
            cin >> cost[i][j];
        }
    }
    cout << tsp(cost) << tata;
    return 0;
}
