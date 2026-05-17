#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        ll a, n, ans = LLONG_MAX, y;
        cin >> a >> n;
        vector<ll> v(n);
        cin >> v[0] >> v[1];
        sajai(v);
        ll l = to_string(a).size();
        if (l > 1)
        {
            ll x = 0;
            for (ll i = 0; i < l - 1; i++)
            {
                x = x * 10 + v[1];
            }
            ans = min(ans, abs(a - x));
        }
        if (v[0] != 0)
            y = v[0];
        else
            y = v[1];
        for (ll i = 0; i < l; i++)
        {
            y = y * 10 + v[0];
        }
        ans = min(ans, abs(a - y));
        string s = to_string(a);
        ll curr = 0;
        ll p = 1;
        for (ll i = 0; i < l; i++)
        {
            ll d = s[i] - '0';
            for (ll x : v)
            {
                if (x > d)
                {
                    ll temp = curr * 10 + x;
                    for (ll j = i + 1; j < l; j++)
                    {
                        temp = temp * 10 + v[0];
                    }
                    ans = min(ans, abs(a - temp));
                }
                else if (x < d)
                {
                    ll temp = curr * 10 + x;
                    for (ll j = i + 1; j < l; j++)
                    {
                        temp = temp * 10 + v[1];
                    }
                    ans = min(ans, abs(a - temp));
                }
            }
            if (d != v[0] && d != v[1])
            {
                p = 0;
                break;
            }
            curr = curr * 10 + d;
        }
        if (p)
            ans = 0;
        cout << ans << tata;
    }
    return 0;
}