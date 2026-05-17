#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y, z) vector<vector<long long>> v((x), vector<long long>((y), (z)))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define db double
#define tata "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<db> x;
    vector<ll> y;
    loop(i, 0, n)
    {
        db a, b, c;
        cin >> a >> b >> c;
        db r = 8000 - 50 * (b + c);
        if (a == b)
        {
            if (r <= 0)
            {
                x.pb(0);
                y.pb(+1);
                x.pb(50);
                y.pb(-1);
            }
        }
        else
        {
            db w = r / (a - b), L = 0, R = 50;
            if (a > b)
                L = w;
            else
                R = w;
            if (L < 0)
                L = 0;
            if (R > 50)
                R = 50;
            if (L <= R)
            {
                x.pb(L);
                y.pb(+1);
                x.pb(R);
                y.pb(-1);
            }
        }
    }
    ll m = x.size();
    vector<ll> l(m);
    loop(i, 0, m) l[i] = i;
    sort(l.begin(), l.end(), [&](ll i, ll j)
         {
             if (x[i] != x[j])
             {
                 return x[i] < x[j];
             }
             return y[i] > y[j]; // start before end
         });

    ll c1 = 0, a1 = 0;
    loop(i, 0, m)
    {
        c1 += y[l[i]];
        a1 = max(a1, c1);
    }
    cout << a1 << tata;
    return 0;
}
