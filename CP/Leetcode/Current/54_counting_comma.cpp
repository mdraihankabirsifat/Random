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
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    long long countCommas(long long n)
    {
        if (n < 1000)
        {
            return 0;
        }
        if (n > 999 && n < 1e6)
        {
            return n - 999;
        }
        if (n > 999999 && n < 1e9)
        {
            // cout << 1000000 - 1000 + 1 << " " << 4590 * 2 << tata;
            return 999002 + 2 * (n - 1e6);
        }
        if (n > 999999999 && n < 1e12)
        {
            return 999002 + 2 * (1e9 - 1e6) + 3 * (n - 1e9) + 1;
        }
        if (n > 999999999999 && n < 1e15)
        {
            //cout << 1 << tata;
            return 999002 + 2 * (1e9 - 1e6) + 3 * (1e12 - 1e9) + 4 * (n - 1e12) + 2;
        }
        if (n == 1e15)
        {
            return 999002 + 2 * (1e9 - 1e6) + 3 * (1e12 - 1e9) + 4 * (1e15 - 1e12) + 3;
        }
        return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {};
    string s = "";
    ll n = 1122872257463;
    Solution sol;
    cout << sol.countCommas(n);
    return 0;
}