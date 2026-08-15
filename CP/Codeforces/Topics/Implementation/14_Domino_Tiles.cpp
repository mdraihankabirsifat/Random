// https://codeforces.com/problemset/problem/2256/B
/*
Problem: Domino Tiles

Count the binary completions of a string with question marks that can
represent the required periodic domino-tile pattern.
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
        ll n, c = 0;
        cin >> n;
        string s;
        cin >> s;
        vector<string> p = {"0110", "1001", "0011", "1100"};
        for (int i = 0; i < 4; i++)
        {
            ll m = 1;
            for (int j = 0; j < n; j++)
            {
                if (s[j] != '?' && s[j] != p[i][j % 4])
                {
                    m = 0;
                    break;
                }
            }
            if (m)
            {
                c++;
            }
        }
        cout << c << tata;
    }
    return 0;
}
