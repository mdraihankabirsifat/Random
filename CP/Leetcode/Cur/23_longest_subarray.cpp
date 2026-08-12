#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        ll n = nums.size(), l = 0, r = 0, c = 0;
        while (r < n)
        {
            m[nums[r]]++;
            while (m[nums[r]] > k)
            {
                m[nums[l]]--;
                l++;
            }
            c = max(c, r - l + 1);
            r++;
        }
        return c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k = 2;
    vector<int> v;
    v = {1, 2, 3, 1, 2, 3, 1, 2};
    Solution sol;
    cout << sol.maxSubarrayLength(v, k);
    return 0;
}