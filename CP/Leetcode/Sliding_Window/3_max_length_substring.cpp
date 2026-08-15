/*
Problem: Maximum Length Substring With Two Occurrences

Find the longest substring in which every character appears at most
twice.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        unordered_map<char, int> m;
        ll n = s.size(), l = 0, r = 0, c = 0;
        while (r < n)
        {
            m[s[r]]++;
            while (m[s[r]] > 2)
            {
                m[s[l]]--;
                l++;
            }
            c = max(c, r - l + 1);
            r++;
        }
        return c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "aaaa";
    Solution sol;
    cout << sol.maximumLengthSubstring(s);
    return 0;
}
