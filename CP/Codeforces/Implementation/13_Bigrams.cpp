// https://codeforces.com/problemset/problem/2242/A
/*
Problem: Bigrams

Determine whether the collection contains enough repeated bigrams to
satisfy the required construction.
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
        ll n, f = 1, c = 0, tr = 0;
        cin >> n;
        vr(v, n);
        in(v);
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 2)
            {
                yes;
                f = 0;
                break;
            }
            else if (v[i] > 1)
            {
                c++;
            }
            if (c > 1)
            {
                yes;
                f = 0;
                break;
            }
        }
        if (f)
        {
            no;
        }
    }
    return 0;
}
