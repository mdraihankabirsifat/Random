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
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> mini(n, 0), maxi(n, 0);
        maxi[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxi[i] = max(nums[i], maxi[i - 1]);
        }
        mini[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            mini[i] = min(nums[i], mini[i + 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (maxi[i] - mini[i] <= k)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {5, 0, 1, 4};
    string s = "";
    ll n = 3;
    Solution sol;
    cout << sol.firstStableIndex(v, n);
    return 0;
}