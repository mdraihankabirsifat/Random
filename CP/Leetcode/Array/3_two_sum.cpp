// https://leetcode.com/problems/two-sum/
/*
Problem: Two Sum

Find the indices of two distinct array elements whose values add up to
the given target.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        ll n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] + nums[j] == target)
                {
                    v.pb(i);
                    v.pb(j);
                    return v;
                }
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v, a;
    v = {2, 7, 15, 11};
    ll t = 9;
    Solution sol;
    a = sol.twoSum(v, t);
    out(a);
    return 0;
}
