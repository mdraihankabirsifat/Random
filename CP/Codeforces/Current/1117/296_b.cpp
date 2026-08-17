#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size() - 1) cin >> v[i]
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
        ll n, m, a = 0, b = 0;
        cin >> n >> m;
        vr(v, n + 1);
        vr(v2, m + 1);
        in(v);
        in(v2);
        v[n] = 1;
        v2[m] = 1;
        for (int i = 0; i < n; i++)
        {
            a += v[i] - v[i + 1] + 1;
        }
        for (int i = 0; i < m; i++)
        {
            b += v2[i] - v2[i + 1] + 1;
        }
        //cout << a << " " << b << tata;
        if (a < b)
        {
            cout << 2 << tata;
        }
        else
        {
            cout << 1 << tata;
        }
    }
    return 0;
}