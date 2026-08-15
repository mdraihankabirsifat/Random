// https://codeforces.com/problemset/problem/2151/C
/*
Problem: Incremental Stay

Pair 2n museum door events as entries and exits under a capacity limit.
For every capacity k, maximize the total visitor stay time.
*/

#include <bits/stdc++.h>
#define ll long long
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
        ll n;
        cin >> n;
        vector<ll> v(2 * n), a(n + 3);
        for (ll i = 0; i < 2 * n; i++)
        {
            cin >> v[i];
        }
        for (ll i = 0; i < 2 * n; i += 2)
        {
            a[1] -= v[i];
        }
        for (ll i = 1; i < 2 * n; i += 2)
        {
            a[1] += v[i];
            a[2] -= v[i];
        }
        for (ll i = 2; i < 2 * n; i += 2)
        {
            a[2] += v[i];
        }
        a[2] += 2 * v[2 * n - 1] - v[0];
        for (ll i = 3; i <= n; i++)
        {
            a[i] = a[i - 2] + 2 * (v[2 * n - i + 1] - v[i - 2]);
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << tata;
    }
}
