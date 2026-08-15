/*
Problem: Minimum Operations to Make a Rotated Palindrome I

Make a lowercase string palindromic using cyclic character increments
and left rotations, minimizing the total number of operations.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size(), c = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            int y = j;
            for (int i = 0; i < n / 2; i++)
            {
                char a = s[(i + j) % n];
                char b = s[(n - 1 - i + j) % n];
                int x = abs(a - b);
                y += min(x, 26 - x);
            }
            c = min(c, y);
        }
        return c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "abbc"; // bbca
    Solution sol;
    cout << sol.minOperations(s);
    return 0;
}