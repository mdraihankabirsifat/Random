// https://codeforces.com/problemset/problem/2225/E
/*
Problem: Covering Points with Circles

Output non-overlapping equal-radius circles with integer centers that
cover at least the required fraction of the given points.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, r, x2, y2, t, x, y, h, p;
    cin >> n >> r;
    h = ceil(sqrt(3) * r);
    set<pair<ll, ll>> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        t = round(1.0 * y / h);
        for (int j = t - 2; j <= t + 2; j++)
        {
            p = ((j & 1) ? r : 0);
            x2 = round(1.0 * (x - p) / (2 * r)) * 2 * r + p;
            y2 = j * h;
            if ((x - x2) * (x - x2) + (y - y2) * (y - y2) <= r * r)
            {
                v.insert({x2, y2});
            }
        }
    }
    cout << v.size() << tata;
    for (auto &[x, y] : v)
    {
        cout << x << " " << y << tata;
    }
    return 0;
}
