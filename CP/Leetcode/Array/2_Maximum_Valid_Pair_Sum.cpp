// https://leetcode.com/problems/maximum-valid-pair-sum/
/*
Problem: Maximum Valid Pair Sum

Among index pairs whose positions differ by at least k, return the
maximum possible sum of their array values.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

class Solution
{
public:
    int maxValidPairSum(vector<int> &nums, int k)
    {
        vector<int> v;
        int n = nums.size();
        int m = 0, p = 0;
        for (int i = k; i < n; i++)
        {
            p = max(p, nums[i - k]);
            m = max(m, p + nums[i]);
        }
        return m;
    }
};
int main()
{
    vector<int> v;
    ll k = 1;
    v.pb(5);
    v.pb(1);
    v.pb(9);
    Solution sol;
    cout << sol.maxValidPairSum(v, k);
    return 0;
}
