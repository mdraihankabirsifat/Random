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
const ll MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    string s;
    cin >> s;
    vector<ll> x(n + 1);
    x[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int p1 = p[i];
        char y = s[i - 2];
        if (y == 'L')
        {
            x[i] = x[p1] - 1;
        }
        else
        {
            x[i] = x[p1] + 1;
        }
    }
    vector<ll> v;
    for (ll i = 1; i <= n; i++)
    {
        v.pb(x[i]);
    }
    sajai(v);
    ll t = 0;
    loop(i,0,n)
    {
        ll c1 = i - (n - 1 - i);
        t += v[i] * c1;
    }
    t %= MOD;
    ll ans = (t * 2) % MOD;
    if (ans < 0)
    {
        ans += MOD;
    }
    cout << ans << "\n";
    return 0;
}