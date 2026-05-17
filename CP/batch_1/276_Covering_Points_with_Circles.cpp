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
    ll n, r, x2, y2, t, x, y, h, p;
    cin >> n >> r;
    h = ceil(sqrt(3) * r);
    set<pair<ll, ll>> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        t = round(1.0 * y / h);
        for (int j = t - 2; j <= t + 2; j++)
        {
            p = ((j & 1) ? r : 0);
            x2 = round(1.0 * (x - p) / (2 * r)) * 2 * r + p;
            y2 = j * h;
            if ((x - x2) * (x - x2) + (y - y2) * (y - y2) <= r * r)
            {
                v.insert({x2, y2});
            }
        }
    }
    cout << v.size() << tata;
    for (auto &[x, y] : v)
    {
        cout << x << " " << y << tata;
    }
    return 0;
}