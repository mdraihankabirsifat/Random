// https://codeforces.com/problemset/problem/2241/F
/*
Problem: A Bit Odd

Play the binary-string game after removing fixed outer runs; determine
the winner from the parity of the remaining runs.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, l = 0, r, zero = 0, one = 0, y = 0;
        cin >> n;
        r = n - 1;
        string s, p;
        cin >> s;
        vector<ll> v, h;
        while (l < n && s[l] == '0')
        {
            l++;
        }
        while (r >= 0 && s[r] == '1')
        {
            r--;
        }
        if (l <= r)
        {
            p = s.substr(l, r - l + 1);
        }
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == '0')
            {
                if (one)
                {
                    h.pb(one);
                    one = 0;
                }
                zero++;
            }
            else
            {
                if (zero)
                {
                    h.pb(zero);
                    zero = 0;
                }
                one++;
            }
        }
        if (one)
        {
            h.pb(one);
        }
        else
        {
            h.pb(zero);
        }
        for (int i = 0; i < h.size(); i++)
        {
            if (h[i] % 2)
            {
                y = 1;
                break;
            }
        }
        if (y)
        {
            cout << "Alice" << tata;
        }
        else
        {
            cout << "Bob" << tata;
        }
        // out(h);
    }
    return 0;
}
