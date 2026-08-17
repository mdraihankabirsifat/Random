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
        ll n, m;
        cin >> n >> m;
        vector<string> s1(n), s2(m);
        vector<bool> v(26, false);
        for (int i = 0; i < n; i++)
        {
            cin >> s1[i];
            ll c = toupper(s1[i][0]);
            v[c - 'A'] = true;
        }
        ll f = 1;
        for (int i = 0; i < m; i++)
        {
            cin >> s2[i];

            if (!f)
            {
                continue;
            }

            for (int j = 0; j < s2[i].size(); j++)
            {
                if (!v[s2[i][j] - 'A'])
                {
                    f = 0;
                    break;
                }
            }
        }
        if (f)
        {
            yes;
        }
        else
            no;
    }
    return 0;
}