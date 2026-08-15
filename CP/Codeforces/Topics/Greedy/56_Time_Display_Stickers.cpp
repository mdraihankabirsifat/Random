// https://codeforces.com/problemset/problem/2206/K
/*
Problem: Time Display Stickers

Using the available digit stickers, build as many valid 24-hour HH:MM
time displays as possible.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c = 0;
        string s;
        cin >> n >> s;
        vector<ll> v(10);
        for (int i = 0; i < n; i++)
        {
            v[s[i] - '0']++;
        }
    here:;
        ll g = 0, h = 0;
        if (v[0])
        {
            v[0]--;
            g = 1;
        }
        else if (v[1] > 1)
        {
            v[1] -= 2;
            h = 1;
            g = -1;
        }
        if (g == 0 && h == 0)
        {
            goto end;
        }
        if (g && !h)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (v[i])
                {
                    v[i]--;
                    g = -1;
                    break;
                }
            }
        }
        if (g == -1)
        {
            for (int i = 5; i >= 0; i--)
            {
                if (v[i])
                {
                    v[i]--;
                    g = -2;
                    break;
                }
            }
        }
        if (g == -2)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (v[i])
                {
                    v[i]--;
                    g = -3;
                    break;
                }
            }
        }
        if (g == -3)
        {
            c++;
        }
        goto here;
    end:;
        cout << c << endl;
    }
    return 0;
}
