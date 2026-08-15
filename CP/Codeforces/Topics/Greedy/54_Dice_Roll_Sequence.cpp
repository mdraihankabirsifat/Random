// https://codeforces.com/problemset/problem/2195/C
/*
Problem: Dice Roll Sequence

Select disjoint adjacent dice rolls that are equal or on opposite faces,
maximizing the number of valid pairs.
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
        ll n, s = 0;
        cin >> n;
        vr(v, n);
        vector<ll> p(n);
        in(v);
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1] == 7 - v[i] && p[i - 1] == 0)
            {
                p[i] = 1;
                s++;
            }
            else if (v[i] == v[i - 1] && p[i - 1] == 0)
            {
                p[i] = 1;
                s++;
            }
        }
        cout << s << tata;
    }
    return 0;
}
