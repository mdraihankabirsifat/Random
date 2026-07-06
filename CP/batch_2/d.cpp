#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

ll lcs(vector<ll> &v1, vector<ll> &v2)
{
    ll n = v1.size(), m = v2.size();
    vector<ll> p(m), c(m);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v1[i] == v2[j])
            {
                c[j] = (j > 0 ? p[j - 1] : 0) + 1;
            }
            else
            {
                ll up = p[j];
                ll left = (j > 0 ? c[j - 1] : 0);
                c[j] = max(up, left);
            }
        }
        p = c;
    }
    return p[m - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        ll n = a.size(), m = b.size();
        vector<ll> v1(n), v2(m);
        v1[0] = (a[0] - '0') % 10;
        for (ll i = 1; i < n; i++)
        {
            v1[i] = (v1[i - 1] + a[i] - '0') % 10;
        }
        v2[0] = (b[0] - '0') % 10;
        for (ll i = 1; i < m; i++)
        {
            v2[i] = (v2[i - 1] + b[i] - '0') % 10;
        }
        if (v1[n - 1] != v2[m - 1])
        {
            cout << -1 << tata;
            continue;
        }
        cout << lcs(v1, v2) << tata;
    }
    return 0;
}