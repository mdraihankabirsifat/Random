#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define tata '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define in(v) loop(i, v.size()) cin >> v[i]
#define out(v) loop(i, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
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