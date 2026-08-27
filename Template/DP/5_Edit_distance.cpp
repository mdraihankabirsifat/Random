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

/*
Minimum insert, delete, and replace operations to change a into b.
Only the previous DP row is required.
Time: O(n * m), Space: O(m).
*/
ll edit_distance(string &a, string &b)
{
    ll n = a.size(), m = b.size();
    vector<ll> prev(m + 1), cur(m + 1);
    loop(j, 0, m + 1)
    {
        prev[j] = j;
    }
    for (ll i = 1; i <= n; i++)
    {
        cur[0] = i;
        for (ll j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                cur[j] = prev[j - 1];
            }
            else
            {
                cur[j] = 1 + min({prev[j], cur[j - 1], prev[j - 1]});
            }
        }
        prev.swap(cur);
    }
    return prev[m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    cout << edit_distance(a, b) << tata;
    return 0;
}
