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
    string s;
    cin >> s;
    ll p = 0;
    vector<ll> v;
    vector<char> a;
    vector<string> x;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '+')
        {
            a.pb(s[i]);
        }
        if (s[i] == '+')
        {
            p++;
        }
        else
        {
            v.pb(p);
            p = 0;
        }
    }
    ll f = 0;
    v.pb(p);
    if (v[0])
    {
        x.pb("(++");
        string str(1, a[0]);
        x.pb(str);
        f = 1;
    }
    else if (v[0] == 0)
    {
        x.pb("(");
        string str(1, a[0]);
        x.pb(str);
    }
    for (int i = 1; i < a.size(); i++)
    {
        if (v[i] == 1)
        {
            x.pb(")+(");
            string str(1, a[i]);
            x.pb(str);
        }
        else if (v[i] == 3 && f)
        {
            x.pb(")+(++");
            string str(1, a[i]);
            x.pb(str);
        }
        else if (v[i] == 3 && !f)
        {
            x.pb("++)+(");
            string str(1, a[i]);
            x.pb(str);
        }
        else if (v[i] == 5)
        {
            x.pb("++)+(++");
            string str(1, a[i]);
            x.pb(str);
        }
    }
    if (v[v.size() - 1] == 2)
    {
        x.pb("++");
    }
    x.pb(")");
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i];
    }
    return 0;
}