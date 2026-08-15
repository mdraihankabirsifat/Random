// https://codeforces.com/problemset/problem/2195/A
/*
Problem: Sieve of Erato67henes

Inspect the given numbers and decide whether the special value 67 is
present.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x = 0, y = 0;
        cin >> n;
        vr(v, n);
        in(v);
        for (int i = 0; i < n; i++)
        {
            // if (v[i] == 1)
            // {
            //     x = 1;
            // }
            if (v[i] == 67)
            {
                y = 1;
            }
        }
        if (y == 1)
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
