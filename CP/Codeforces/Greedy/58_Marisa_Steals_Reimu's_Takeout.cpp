// https://codeforces.com/problemset/problem/2228/A
/*
Problem: Marisa Steals Reimu's Takeout

Remove nonempty subsequences whose sums are divisible by 3, maximizing
the number of removal operations.
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
        ll n, a = 0, b = 0, c = 0;
        cin >> n;
        vr(v, n);
        in(v);
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
            {
                a++;
            }
            else if (v[i] == 1)
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        a += min(b, c);
        if (b != c)
        {
            a += abs(b - c) / 3;
        }
        cout << a << tata;
    }
    return 0;
}
