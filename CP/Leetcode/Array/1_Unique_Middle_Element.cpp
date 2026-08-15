/*
Problem: Unique Middle Element

Determine whether the element at the array's middle index occurs
exactly once in the entire array.
*/
#include <bits/stdc++.h>
using namespace std;
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
    vector<int> v = {1, 2, 3, 2, 3};
    Solution sol;
    cout << sol.isMiddleElementUnique(v);
    return 0;
}
