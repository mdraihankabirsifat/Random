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
        vector<int> v(n), v1, v2, v3;
        in(v);
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 6 == 0)
            {
                cout << v[i] << " ";
            }
            else if (v[i] % 2 == 0)
            {
                v3.pb(v[i]);
            }
            else if (v[i] % 2 != 0 && v[i] % 3 != 0)
            {
                v1.pb(v[i]);
            }
            else
            {
                v2.pb(v[i]);
            }
        }
        for (int i = 0; i < v3.size(); i++)
        {
            cout << v3[i] << " ";
        }
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        for (int i = 0; i < v2.size(); i++)
        {
            cout << v2[i] << " ";
        }
        cout << tata;
    }
    return 0;
}