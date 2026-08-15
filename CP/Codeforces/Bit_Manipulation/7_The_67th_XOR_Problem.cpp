// https://codeforces.com/problemset/problem/2218/E
/*
Problem: The 67th XOR Problem

Repeatedly XOR all values by a chosen value and remove that value;
maximize the final number left in the array.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
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
        ll n, m = 0;
        cin >> n;
        vr(v, n);
        in(v);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                m = max(m, v[i] ^ v[j]);
            }
        }
        cout << m << tata;
    }
    return 0;
}
