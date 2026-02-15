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
        ll n;
        cin >> n;
        vr(v, n + 1);
        vector<ll> p(n + 1), v2(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        v2 = v;
        for (int i = 1; i <= n; i++)
        {
            if (!p[i])
            {
                vector<ll> g, h;
                for (int j = i; j <= n; j = 2 * j)
                {
                    g.pb(v[j]);
                    h.pb(j);
                    p[j] = 1;
                }
                sajai(g);
                sajai(h);
                if (g != h)
                {
                    no;
                    goto end;
                }
            }
        }
        yes;
    end:;
    }
    return 0;
}