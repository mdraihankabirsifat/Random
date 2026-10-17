// https://codeforces.com/problemset/problem/2274/A
/*
Problem: The Projections of Paco

Find the unique initial reflection point that makes a token return to zero
after being reflected across every given point in order.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
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
        ll n, s = 0;
        cin >> n;
        vector<ll> v(n);
        in(v);
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                s -= v[i];
            }
            else
            {
                s += v[i];
            }
        }
        cout << s << tata;
    }
    return 0;
}
