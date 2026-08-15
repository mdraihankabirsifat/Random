// https://codeforces.com/problemset/problem/2195/D
/*
Problem: Absolute Cinema

Reconstruct the original array from the supplied neighboring linear
combinations used by the cinema transformation.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
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
        ll n;
        cin >> n;
        vr(v, n);
        in(v);
        vr(a, n);
        ll s = (v[0] + v[n - 1]) / (n - 1);
        a[0] = (s + v[1] - v[0]) / 2;
        a[n - 1] = (s - v[n - 1] + v[n - 2]) / 2;
        loop(i, 1, n - 1)
        {
            a[i] = (v[i - 1] - 2 * v[i] + v[i + 1]) / 2;
        }
        out(a);
        cout << tata;
    }
    return 0;
}
