// https://codeforces.com/problemset/problem/2178/A
/*
Problem: Yes or Yes

Given a string of Y and N characters, decide whether it contains at
most one occurrence of Y.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define yes cout << "YES" << tata
#define no cout << "NO" << tata
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
        ll c = 0;
        string s;
        cin >> s;
        loop(i, 0, s.size())
        {
            if (s[i] == 'Y')
            {
                c++;
            }
        }
        if (c == 1 || c == 0)
        {
            yes;
        }
        else
        {
            no;
        }
    }
    return 0;
}
