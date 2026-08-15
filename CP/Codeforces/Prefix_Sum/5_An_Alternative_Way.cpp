// https://codeforces.com/problemset/problem/2241/D
/*
Problem: An Alternative Way

Compare prefix resources in two arrays and decide whether the requested
transformation can be completed without any prefix deficit.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
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
        ll n, s = 0, f = 0;
        cin >> n;
        vr(a, n);
        vr(b, n);
        in(a);
        in(b);
        for (int i = 0; i < n; i++)
        {
            s = s + b[i] - a[i];
            if (s < 0)
            {
                f = 1;
                break;
            }
        }
        if (f)
        {
            no;
        }
        else
        {
            yes;
        }
    }
    return 0;
}
