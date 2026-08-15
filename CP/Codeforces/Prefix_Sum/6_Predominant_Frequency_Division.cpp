// https://codeforces.com/problemset/problem/2242/B
/*
Problem: Predominant Frequency Division

Decide whether the array can be divided into consecutive parts meeting
the prescribed predominant-frequency conditions.
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
        ll n, f = 1;
        cin >> n;
        vr(v, n);
        in(v);
        vector<ll> l(n + 1), m(n + 1), s(n + 2, LLONG_MIN);

        for (ll i = 1; i <= n; i++)
        {
            l[i] = l[i - 1];
            m[i] = m[i - 1];
            if (v[i - 1] == 1)
            {
                l[i]++;
                m[i]++;
            }
            else if (v[i - 1] == 2)
            {
                l[i]--;
                m[i]++;
            }
            else
            {
                l[i]--;
                m[i]--;
            }
        }
        for (ll i = n - 1; i >= 1; i--)
        {
            s[i] = max(s[i + 1], m[i]);
        }
        for (ll i = 1; i <= n - 2; i++)
        {
            if (l[i] >= 0 && s[i + 1] >= m[i])
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
