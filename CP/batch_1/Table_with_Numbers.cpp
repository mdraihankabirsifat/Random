#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
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