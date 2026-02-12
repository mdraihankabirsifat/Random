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

ll sum(ll n)
{
    ll s = 0;
    while (n)
    {
        s = s + (n % 10);
        n = n / 10;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, f = 0;
        cin >> n;
        loop(i, n, n + 81)
        {
            if (i - sum(i) == n)
            {
                cout << 10 << tata;
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << 0 << tata;
        }
    }
    return 0;
}