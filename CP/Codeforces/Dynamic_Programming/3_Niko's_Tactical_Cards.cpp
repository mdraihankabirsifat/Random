// https://codeforces.com/problemset/problem/2173/B
/*
Problem: Niko's Tactical Cards

Process two rows of tactical card values while tracking all reachable score
differences, then output the maximum final score.
*/

#include <bits/stdc++.h>
#define ll long long
#define tata '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define in(v) loop(i, v.size()) cin >> v[i]
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, l1 = 0, r1 = 0;
        cin >> n;
        vector<ll> a(n), b(n);
        in(a);
        in(b);
        loop(i, n)
        {
            ll l2 = min(l1 - a[i], b[i] - r1);
            ll r2 = max(r1 - a[i], b[i] - l1);
            l1 = l2;
            r1 = r2;
        }
        cout << r1 << tata;
    }
    return 0;
}
