// 3876
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
    bool uniformArray(vector<int> &v)
    {
        int n = v.size(), c = 0, m1 = INT_MAX, m2 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                c++;
                m1 = min(m1, v[i]);
            }
            else
            {
                m2 = min(m2, v[i]);
            }
        }
        if (m2 < m1 || c == n || c == 0)
        {
            return true;
        }
        return false;
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