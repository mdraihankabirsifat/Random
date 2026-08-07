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
        ll n, c = 1;
        cin >> n;
        vr(v, n);
        vector<ll> p, cnt;
        in(v);
        p.pb(v[0]);
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
            {
                p.pb(v[i]);
                cnt.pb(c);
                c = 1;
            }
            else
            {
                c++;
            }
        }
        cnt.pb(c);
        ll m = p.size(), ans = m;
        for (int i = 0; i < m - 1; i++)
        {
            ll temp = 0;
            if (cnt[i] >= 2)
            {
                temp++;
            }
            else if (i > 0 && p[i - 1] == p[i + 1])
            {
                temp--;
            }
            if (cnt[i + 1] >= 2)
            {
                temp++;
            }
            else if (i + 2 < m && p[i] == p[i + 2])
            {
                temp--;
            }
            ans = max(ans, m + temp);
        }
        cout << ans << tata;
    }
    return 0;
}