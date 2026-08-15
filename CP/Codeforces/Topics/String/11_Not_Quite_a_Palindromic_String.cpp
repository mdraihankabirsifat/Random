// https://codeforces.com/problemset/problem/2114/B
/*
Problem: Not Quite a Palindromic String

Rearrange a binary string so exactly k mirrored position pairs contain
equal characters, or report that this is impossible.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, s1 = 0, s0 = 0;
        string s;
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                s1++;
            }
            else
            {
                s0++;
            }
        }
        int mn = max(s1, s0) - n / 2;
        int mx = (s1 + s0) / 2;
        if (k >= mn && (k - mn) % 2 == 0 && k <= mx)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    return 0;
}
