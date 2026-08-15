// https://codeforces.com/problemset/problem/2229/A
/*
Problem: Slimes on a Line

Place all slimes at one integer point on a line and minimize the maximum
distance any slime must travel.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

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
        vr(v, n);
        in(v);
        cout << round((boro(v) - choto(v)) / 2.0) << tata;
    }
    return 0;
}
