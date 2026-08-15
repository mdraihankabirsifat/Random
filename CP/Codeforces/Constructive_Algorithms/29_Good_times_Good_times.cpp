// https://codeforces.com/problemset/problem/2241/B
/*
Problem: Good times Good times

For the given decimal length, construct the smallest number matching
the required recursive good-times pattern.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll y = 1;
        for (int i = 0; i < s.size(); i++)
        {
            y = y * 10;
        }
        y++;
        cout << y << tata;
    }
    return 0;
}
