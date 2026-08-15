/*
Problem: Find the Lexicographically Smallest Valid Sequence

Return the lexicographically smallest indices in word1 that match word2
as a subsequence while allowing at most one mismatched character.
*/
#include <bits/stdc++.h>
using namespace std;
#define tata "\n"
class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.size(), m = word2.size(), c = 0, r, m1 = 0, j = 0;
        r = m - 1;
        vector<int> v(n), a;
        for (int i = n - 1; i >= 0; i--)
        {
            v[i] = c;
            if (r >= 0 && word1[i] == word2[r])
            {
                r--;
                c++;
            }
        }
        for (int i = 0; i < n && j < m; i++)
        {
            if (word1[i] == word2[j])
            {
                a.push_back(i);
                j++;
            }
            else if (m1 == 0 && v[i] >= m - 1 - j)
            {
                a.push_back(i);
                j++;
                m1 = 1;
            }
        }
        if (m == j)
        {
            return a;
        }
        return {};
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> s;
    Solution sol;
    s = sol.validSequence(s1, s2);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << tata;
    return 0;
}
