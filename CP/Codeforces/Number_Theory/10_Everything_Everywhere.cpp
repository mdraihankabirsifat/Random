// https://codeforces.com/problemset/problem/2226/B
/*
Problem: Everything Everywhere

Count adjacent pairs whose absolute difference equals their greatest
common divisor.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

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
        vr(v, n);
        in(v);
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(v[i] - v[i + 1]) == __gcd(v[i], v[i + 1]))
            {
                c++;
            }
        }
        cout << c << tata;
    }
    return 0;
}
