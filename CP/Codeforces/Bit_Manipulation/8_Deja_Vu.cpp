// https://codeforces.com/problemset/problem/1891/B
/*
Problem: Deja Vu

For each query x, add 2^(x-1) to every array value divisible by 2^x,
then output the final array.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        ll n, q;
        cin >> n >> q;
        vector<ll> v(n), p(q);
        in(v);
        in(p);
        
    }
    return 0;
}
