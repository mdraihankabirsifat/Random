// https://codeforces.com/problemset/problem/2189/A
/*
Problem: Table with Numbers

Pair table numbers under separate height and length limits, with one
number satisfying each limit, and maximize the number of valid pairs.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
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
        ll n, h, l, hm = 0, lm = 0;
        cin >> n >> h >> l;
        vector<int> v(n);
        in(v);
        loop(i, 0, n)
        {
            if (v[i] <= h)
            {
                hm++;
            }
            if (v[i] <= l)
            {
                lm++;
            }
        }
        //cout << lm << " " << hm << tata;
        // cout << min(min(hm, lm), abs(lm - hm)) << tata;
        ll m = max(hm, lm);
        ll s = min(lm, hm);
        ll ans = 0;
        ans = min(m - s, s);
        //cout << ans << tata;
        if (s > (m - s))
        {
            ans += (s-ans) / 2;
            //cout << ans << tata;
        }
        cout << ans << tata;
    }
    return 0;
}
