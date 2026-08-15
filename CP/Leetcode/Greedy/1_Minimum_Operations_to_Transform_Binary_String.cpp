// https://leetcode.com/problems/minimum-operations-to-transform-binary-string/
/*
Problem: Minimum Operations to Transform Binary String

Transform one binary string into another by changing a zero to one or
changing an adjacent pair of ones to zeros, using as few operations as possible.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s1, string s2)
    {
        string s3 = s1;
        string s4 = s2;
        int s = 0;
        if (s1.size() == 1 && s1[0] == '1' && s2[0] == '0')
        {
            return -1;
        }
        if (s1.size() == 1 && s1[0] == '0' && s2[0] == '1')
        {
            return 1;
        }
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0')
            {
                s1[i] = '0';
                s1[i + 1] = '0';
                s += 1;
            }
        }
        for (int i = 0; i < s1.size(); i = i + 2)
        {
            if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1'))
            {
                s += 1;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 2;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 3;
            }
        }

        if (s1.size() % 2)
        {
            if (s1[s1.size() - 1] == '0' && s2[s1.size() - 1] == '1')
            {
                s += 1;
            }
            else if (s1[s1.size() - 1] == '1' && s2[s1.size() - 1] == '0')
            {
                s += 2;
            }
        }
        int p = s;
        s = 0;
        s1 = s3;
        s2 = s4;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0')
            {
                s1[i] = '0';
                s1[i + 1] = '0';
                s += 1;
            }
        }
        for (int i = 0; i < s1.size(); i = i + 2)
        {
            if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1'))
            {
                s += 1;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 2;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 3;
            }
        }

        if (s1.size() % 2)
        {
            if (s1[s1.size() - 1] == '0' && s2[s1.size() - 1] == '1')
            {
                s += 1;
            }
            else if (s1[s1.size() - 1] == '1' && s2[s1.size() - 1] == '0')
            {
                s += 2;
            }
        }
        int l = min(s, p);
        return l;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "11";
    string s2 = "00";
    Solution sol;
    cout << sol.minOperations(s1, s2);
    return 0;
}
