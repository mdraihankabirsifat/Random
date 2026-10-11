#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

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
        vector<ll> v(n);
        in(v);
        ll mx = v[0], mn = v[0], p = v[0];
        for (int i = 1; i < n; i++)
        {
            p = max({p, v[i] + mx, v[i] - mn, v[i]});
            ll a = 2 * mx + v[i];
            ll b = 2 * mn + v[i];
            ll c = mx + v[i];
            ll d = mn + v[i];
            mx = max({a, b, c, d, v[i]});
            mn = min({a, b, c, d, v[i]});
        }
        cout << p << tata;
    }
    return 0;
}