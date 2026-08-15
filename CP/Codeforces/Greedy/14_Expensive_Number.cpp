// https://codeforces.com/problemset/problem/2093/B
/*
Problem: Expensive Number

Delete digits while preserving order to minimize a number's cost,
and output the minimum number of deletions.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int f = 0, c = 0;
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (f == 1 && s[i] == '0')
            {
                c++;
            }
            if (s[i] != '0')
            {
                f = 1;
            }
        }
        printf("%d\n", s.size() - (c + 1));
    }
    return 0;
}
