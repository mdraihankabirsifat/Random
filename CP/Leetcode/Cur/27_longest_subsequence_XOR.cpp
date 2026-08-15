#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define bit(n) __builtin_popcountll(n)

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