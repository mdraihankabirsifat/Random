// https://leetcode.com/problems/gray-code/
/*
Problem: Gray Code

Generate all 2^n values in a Gray-code ordering where consecutive values,
including the last and first, differ in exactly one bit.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        int x = pow(2, n);
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        if (n == 1)
        {
            return v;
        }
        v.push_back(3);
        v.push_back(2);
        for (int i = 3; i <= n; i++)
        {
            int j = (i - 2);
            vector<int> v1;
            v1 = v;
            reverse(v1.begin(), v1.end());
            for (int k = 0; k < v1.size(); k++)
            {
                v.push_back(v1[k] + pow(2, j + 1));
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Solution sol;
    vector<int> v;
    v = sol.grayCode(n);
    out(v);
    return 0;
}
