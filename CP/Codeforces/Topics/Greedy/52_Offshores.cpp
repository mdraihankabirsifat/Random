// https://codeforces.com/problemset/problem/2194/B
/*
Problem: Offshores

Keep at most one company onshore while converting every other value at
the given exchange rate, maximizing the final total.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
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
        ll n, x, y, s = 0, m, a = 0;
        cin >> n >> x >> y;
        vector<ll> v(n);
        in(v);
        loop(i, 0, n)
        {
            s += v[i] / x * y;
        }
        loop(i, 0, n)
        {
            m = s - v[i] / x * y + v[i];
            a = max(m, a);
        }
        cout << a << tata;
    }
    return 0;
}
