#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define jora(p, n) pair<ll, ll> p(n)
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
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> v1, v2, v;
        sajai(nums);
        ll n = nums.size();
        for (int i = 1; i < n; i = i + 2)
        {
            v1.pb(nums[i]);
        }
        for (int i = 0; i < n; i = i + 2)
        {
            v2.pb(nums[i]);
        }
        ll j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                v.pb(v2[j]);
                j++;
            }
            else
            {
                v.pb(v1[j]);
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    v = {6, 4, 5, 1, 3, 2};
    // in(v);
    Solution sol;
    sol.numberGame(v);
    return 0;
}