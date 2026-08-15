// https://leetcode.com/problems/minimum-number-game/
/*
Problem: Minimum Number Game

Repeatedly remove the two smallest numbers and append them in reversed
player order, then return the resulting array.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sajai(x) sort(x.begin(), x.end())

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
