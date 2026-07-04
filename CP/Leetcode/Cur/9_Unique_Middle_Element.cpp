#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
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
class Solution
{
public:
    bool isMiddleElementUnique(vector<int> &nums)
    {
        long long n = nums.size(), c = 0;
        long long n1 = floor(n / 2);
        long long p = nums[n1];
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == p)
            {
                c++;
            }
        }
        if (c > 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
int main()
{
    vector<int> v;
    v.pb(1);
    v.pb(2);
    v.pb(3);
    v.pb(2);
    v.pb(3);
    Solution sol;
    cout << sol.isMiddleElementUnique(v);
    return 0;
}