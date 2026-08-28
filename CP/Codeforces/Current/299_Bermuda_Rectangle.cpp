#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define sajai(x) sort(x.begin(), x.end())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll s, q;
        cin >> s >> q;
        vector<ll> v;
        v.pb(0);
        for (ll i = 1; i * i <= s; i++)
        {
            if (s % i == 0)
            {
                v.pb(i);
                if (i != s / i)
                {
                    v.pb(s / i);
                }
            }
        }
        sajai(v);
        ll n = v.size();
        vector<ll> p(n);
        for (int i = 1; i < n; i++)
        {
            p[i] = p[i - 1] + (v[i] - v[i - 1]) * (s / v[i]);
        }
        while (q--)
        {
            ll x, y, a, b, c, d, ans = 0, nxt = LLONG_MAX;
            cin >> x >> y;
            c = min(s / y, x);
            a = lower_bound(v.begin(), v.end(), c) - v.begin();
            if (v[a] != c)
            {
                a--;
            }
            b = lower_bound(v.begin(), v.end(), x) - v.begin();
            if (b >= n || v[b] != x)
            {
                b--;
                if (b + 1 < n)
                {
                    nxt = v[b + 1];
                }
                d = min(s / nxt, y);
                ans += d * (x - v[b]);
            }
            ans += v[a] * y + p[b] - p[a];
            cout << ans << tata;
        }
    }
    return 0;
}