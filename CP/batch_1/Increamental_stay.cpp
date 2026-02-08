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
        ll n;
        cin >> n;
        vector<ll> v(2 * n), a(n + 3);
        for (ll i = 0; i < 2 * n; i++)
        {
            cin >> v[i];
        }
        for (ll i = 0; i < 2 * n; i += 2)
        {
            a[1] -= v[i];
        }
        for (ll i = 1; i < 2 * n; i += 2)
        {
            a[1] += v[i];
            a[2] -= v[i];
        }
        for (ll i = 2; i < 2 * n; i += 2)
        {
            a[2] += v[i];
        }
        a[2] += 2 * v[2 * n - 1] - v[0];
        for (ll i = 3; i <= n; i++)
        {
            a[i] = a[i - 2] + 2 * (v[2 * n - i + 1] - v[i - 2]);
        }
        for (ll i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << tata;
    }
}