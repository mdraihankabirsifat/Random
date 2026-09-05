// 3903
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
    int firstStableIndex(vector<int> &v, int k)
    {
        int n = v.size();
        int ans = INT_MAX, y = -1, f = 0;
        vector<int> p;
        for (int i = 0; i < n; i++)
        {
            int Max = *max_element(v.begin(), v.begin() + i + 1);
            int Min = *min_element(v.begin() + i, v.end());
            cout << i << ": " << Max << " " << Min << tata;
            if (Max - Min <= k && Max - Min >= 0)
            {
                int temp = ans;
                ans = min(ans, Max - Min);
                // cout << temp << " " << ans << tata;
                if (temp > ans)
                {
                    p.pb(i);
                    f = 1;
                }
            }
        }
        if (f)
        {
            sajai(p);
            return p[0];
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {6, 1, 4};
    // cout << *max(v.begin(), v.begin() + 2);
    string s = "";
    ll n = 5;
    Solution sol;
    cout << sol.firstStableIndex(v, n);
    return 0;
}