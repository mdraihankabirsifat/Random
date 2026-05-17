#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define rsort(a) sort(a.begin(), a.end(), greater<>())
#define ulta(a) reverse(a.begin(), a.end())
#define mucho(a, j) a.erase(a.begin() + j)
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define bit(n) __builtin_popcountll(n)
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
        ll n, k, p, m, temp = 0, c = 0, tz, f = 1;
        cin >> n >> k >> p >> m;
        vr(v, n);
        in(v);
        tz = v[p - 1];
        while (temp < m)
        {
            f = 1;
            if (p == k)
            {
                temp += tz;
                if (temp <= m)
                {
                    c++;
                    p = n;
                    mucho(v, k - 1);
                    v.pb(tz);
                }
                f = 0;
                // out(v);
                // cout << " First" << tata;
            }
            if (f)
            {
                for (int i = 0; i < k; i++)
                {
                    if (v[i] == tz && p < k)
                    {
                        temp += v[i];
                        if (temp <= m)
                        {
                            p = n;
                            c++;
                            mucho(v, i);
                            v.pb(tz);
                        }
                        f = 0;
                        break;
                    }
                }
            }
            if (f)
            {
                ll x = *min_element(v.begin(), v.begin() + k);
                for (int i = 0; i < k; i++)
                {
                    if (v[i] == x)
                    {
                        temp += v[i];
                        if (temp <= m)
                        {
                            p--;
                            mucho(v, i);
                            v.pb(x);
                        }
                        break;
                    }
                }
            }
        }
        cout << c << tata;
    }
    return 0;
}