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
        ll n, a, b;
        cin >> n >> a;
        vector<ll>v(n);
        ll t = n, f = 0;
        ll j = LLONG_MAX;
        in(v);
        b = v[0];
        loop(i, n)
        {
            if (a == v[i])
            {
                j = min(j, i);
                f = 1;
            }
            else if (a < v[i])
            {
                t = i;
                break;
            }
        }
        if (f)
        {
            if (j >= (n - t))
            {
                if (j > 0)
                    b = v[j - 1];
            }
            else
            {
                if (t < n)
                    b = v[t];
            }
        }
        else
        {
            if (t >= (n - t))
            {
                if (t > 0)
                    b = v[t - 1];
            }
            else
            {
                if (t < n)
                    b = v[t];
            }
        }
        cout << b << endl;
    }
    return 0;
}