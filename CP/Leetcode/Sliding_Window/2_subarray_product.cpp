/*
Problem: Subarray Product Less Than K

Count all contiguous subarrays whose combined product is strictly
less than k.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        ll n = nums.size(), l = 0, c = 0, p = 1;
        for (int i = 0; i < n; i++)
        {
            p *= nums[i];
            while (p >= k)
            {
                p /= nums[l];
                l++;
            }
            c+=i-l+1;
        }
        return c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k = 100;
    vector<int> v = {10, 5, 2, 6};
    Solution sol;
    cout << sol.numSubarrayProductLessThanK(v, k);
    return 0;
}
