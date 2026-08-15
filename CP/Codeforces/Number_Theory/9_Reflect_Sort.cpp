// https://codeforces.com/problemset/problem/2206/H
/*
Problem: Reflect Sort

Determine whether one sequence can be transformed into the other using
reflections, using the invariant induced by adjacent differences.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n" 
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, g = 0;
    cin >> n;
    vector<ll> v(n);
    in(v);
    loop(i, 1, n)
    {
        g = __gcd(g, 2 * abs(v[i] - v[i - 1]));
    }
    if (g)
    {
        g = (v[0] - 1) % g + 1;
    }
    else
    {
        g = v[0];
    }
    loop(i, 1, n)
    {
        g += abs(v[i] - v[i - 1]);
    }
    cout << g << tata;
    return 0;
}
