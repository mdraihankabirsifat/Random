// https://codeforces.com/problemset/problem/2207/A
/*
Problem: 1-1

A bit between two ones may be changed freely; find the minimum and
maximum possible number of ones after any sequence of moves.
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
        ll n, one = 0, zero = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
        }
        zero = n - one;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1')
            {
                s[i] = '1';
                one++;
                zero--;
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1')
            {
                s[i] = '0';
                zero++;
            }
        }
        cout << n - zero << " " << one << tata;
    }
    return 0;
}
