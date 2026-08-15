// https://codeforces.com/problemset/problem/2210/B
/*
Problem: Simply Sitting on Chairs

Visit chairs from left to right; sitting at chair i marks chair p[i],
and the game stops at a marked chair. Maximize chairs sat on.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        ll n;
        cin >> n;
        vr(v, n);
        in(v);
        
    }
    return 0;
}
