#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> a, b;
        a = {nums[0]};
        b = {nums[1]};
        for (int i = 2; i < nums.size(); i++)
        {
            if (a.back() > b.back())
            {
                a.pb(nums[i]);
            }
            else
            {
                b.pb(nums[i]);
            }
        }
        for (auto it : b)
        {
            a.pb(it);
        }
        return a;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    Solution sol;
    // cout << sol.;
    return 0;
}