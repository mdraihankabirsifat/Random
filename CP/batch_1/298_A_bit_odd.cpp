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
        ll n, l = 0, r, zero = 0, one = 0, y = 0;
        cin >> n;
        r = n - 1;
        string s, p;
        cin >> s;
        vector<ll> v, h;
        while (l < n && s[l] == '0')
        {
            l++;
        }
        while (r >= 0 && s[r] == '1')
        {
            r--;
        }
        if (l <= r)
        {
            p = s.substr(l, r - l + 1);
        }
        for (int i = 0; i < p.size(); i++)
        {
            if (p[i] == '0')
            {
                if (one)
                {
                    h.pb(one);
                    one = 0;
                }
                zero++;
            }
            else
            {
                if (zero)
                {
                    h.pb(zero);
                    zero = 0;
                }
                one++;
            }
        }
        if (one)
        {
            h.pb(one);
        }
        else
        {
            h.pb(zero);
        }
        for (int i = 0; i < h.size(); i++)
        {
            if (h[i] % 2)
            {
                y = 1;
                break;
            }
        }
        if (y)
        {
            cout << "Alice" << tata;
        }
        else
        {
            cout << "Bob" << tata;
        }
        // out(h);
    }
    return 0;
}