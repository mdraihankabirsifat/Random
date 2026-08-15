// https://codeforces.com/problemset/problem/2241/C
/*
Problem: RemovevomeR

For a binary string, find the minimum number of RemovevomeR operations
needed according to its transitions.
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
        if (n > 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] != s[i + 1])
                {
                    c++;
                }
            }
            if (c == 1)
            {
                cout << 2 << tata;
            }
            else
                cout << 1 << tata;
        }
        else
            cout << 1 << tata;
    }
    return 0;
}
