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
        ll n, k, r = 0, b = 0;
        cin >> n >> k;
        string s, s1;
        cin >> s;
        s1 = s;
        for (int i = 0; i < 2 * n; i++)
        {
            ll temp = (i + 1) % (2 * n);
            if (s[i] == '1' && s[temp] == '0')
            {
                s1[i] = '0';
                s1[temp] = '1';
            }
        }
        for (int i = 0; i < 2 * n; i++)
        {
            if (i % 2 && s1[i] == '1')
            {
                r++;
            }
            else if (i % 2 == 0 && s1[i] == '1')
            {
                b++;
            }
        }
        cout << r << " " << b << tata;
    }
    return 0;
}