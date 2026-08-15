// https://codeforces.com/problemset/problem/2189/C1
/*
Problem: XOR Convenience (Easy Version)

Construct a permutation in which every required interior position has
a later value satisfying the specified XOR relation.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
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
        ll n, i = 0;
        cin >> n;
        vector<ll> v(n), p(n + 1);
        p[1] = 1;
        for (i = 1; i < n - 1; i++)
        {
            v[i] = (i + 1) ^ 1;
            p[(i + 1) ^ 1] = 1;
        }
        v[i] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!p[i])
            {
                v[0] = i;
                break;
            }
        }
        out(v);
        cout << tata;
    }
    return 0;
}
