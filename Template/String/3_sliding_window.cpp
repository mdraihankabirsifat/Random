#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

// ---------------------------------------------------------
// Sliding Window
// Longest substring where every character appears at most k times
//
// Time Complexity : O(n)
// Space Complexity: O(number of distinct characters)
// ---------------------------------------------------------
ll longestSubstringAtMostKFrequency(string &s, ll k)
{
    unordered_map<char, ll> m;
    ll n = s.size(), l = 0, ans = 0;
    for (int r = 0; r < n; r++)
    {
        m[s[r]]++;
        while (m[s[r]] > k)
        {
            m[s[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "aaaa";
    cout << longestSubstringAtMostKFrequency(s, 2) << tata; // 2
    return 0;
}

/*
===========================================================
SLIDING WINDOW FREQUENCY TEMPLATE
===========================================================

Window = [l ... r]

1. Expand right:
       m[s[r]]++;

2. If current window becomes invalid:
       while(invalid)
       {
           m[s[l]]--;
           l++;
       }

3. Now window is valid:
       ans = max(ans, r - l + 1);

For Leetcode 3090:
    longestSubstringAtMostKFrequency(s, 2);

Condition:
    Each character can appear at most 2 times.

Time Complexity: O(n)
because each character enters and leaves the window
at most once.
*/