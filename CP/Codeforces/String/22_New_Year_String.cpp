// https://codeforces.com/problemset/problem/2182/A
/*
Problem: New Year String

Change the fewest characters so the string contains "2026" while
respecting the condition involving occurrences of "2025".
*/

#include <bits/stdc++.h>
#define ll long long
#define tata "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (int i = 3; i < n; i++)
        {
            if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2' && s[i] == '6')
            {
                a = 1;
            }
            if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2' && s[i] == '5')
            {
                b = 1;
            }
        }
        if (!a && b)
        {
            cout << 1 << tata;
        }
        else
        {
            cout << 0 << tata;
        }
    }
    return 0;
}
