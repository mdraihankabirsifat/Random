// https://codeforces.com/problemset/problem/2273/A
/*
Problem: Lavencia Oranges

Construct an assignment of oranges to bags that minimizes the largest number
of oranges confiscated from bags having an equal size.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, p = 1, b = 1;
        cin >> n;
        while (true)
        {
            ll mx = 0;
            for (ll i = 1; i < p + 1; i++)
            {
                mx += (p / i) * i;
            }
            if (mx >= n)
            {
                break;
            }
            p++;
        }
        cout << p << tata;
        vector<ll> a;
        for (ll i = p; i > 0; i--)
        {
            for (ll j = 0; j < p / i; j++)
            {
                if (n >= i)
                {
                    n -= i;
                    for (ll k = 0; k < i; k++)
                    {
                        a.pb(b);
                    }
                    b++;
                }
            }
        }
        out(a);
        cout << tata;
    }
    return 0;
}
