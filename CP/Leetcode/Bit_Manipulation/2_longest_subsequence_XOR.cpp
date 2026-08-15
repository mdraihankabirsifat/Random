/*
Problem: Longest Subsequence With Non-Zero Bitwise XOR

Return the maximum length of a subsequence whose combined bitwise XOR
is nonzero, or zero if no such subsequence exists.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        ll n = nums.size(), p = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            p = p ^ nums[i];
            if (nums[i] == 0)
            {
                z++;
            }
        }
        if (p)
        {
            return n;
        }
        else
        {
            if (z == n)
            {
                return 0;
            }
            else
            {
                return n - 1;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {1, 2, 3};
    Solution sol;
    cout << sol.longestSubsequence(v);
    return 0;
}
