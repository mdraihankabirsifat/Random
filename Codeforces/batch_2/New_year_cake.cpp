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

ll solve(ll a, ll b, ll i)
{
    ll c = 0, f1 = 1;
    if ((a - i) >= 0)
    {
        c++;
    }
    else
    {
        f1 = 0;
    }
    if ((b - i * 2) >= 0 && f1)
    {
        c++;
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, i = 1, a1, b1, c = 0, c1 = 0;
        cin >> a >> b;
        a1 = a;
        b1 = b;
        while (1)
        {
            ll p1 = solve(a, b, i);
            if (p1)
            {
                a -= i;
                b -= i * 2;
                c += p1;
            }
            ll p2 = solve(b1, a1, i);
            if (p2)
            {
                a1 -= i * 2;
                b1 -= i;
                c1 += p2;
            }
            if (!(p1 && p2))
            {
                break;
            }
            i = i * 4;
        }
        cout << max(c, c1) << tata;
    }
    return 0;
}