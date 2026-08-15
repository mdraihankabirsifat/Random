// https://codeforces.com/problemset/problem/2238/A
/*
Problem: Another Puzzle from Papyrus

Match two arrays directly or after reordering, paying the optional cost
when reordering is necessary; output the minimum result or -1.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define sajai(x) sort(x.begin(), x.end())
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
        ll n, c;
        cin >> n >> c;
        vr(a, n);
        vr(b, n);
        in(a);
        in(b);
        ll s = 0, p = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= b[i])
            {
                s = s + (a[i] - b[i]);
            }
            else
            {
                p = 1;
                break;
            }
        }
        if (p)
        {
            ll x = 0;
            s = c;
            sajai(a);
            sajai(b);
            for (int i = 0; i < n; i++)
            {
                if (a[i] >= b[i])
                {
                    s = s + (a[i] - b[i]);
                }
                else
                {
                    x = 1;
                    break;
                }
            }
            if (x)
            {
                cout << -1 << tata;
            }
            else
            {
                cout << s << tata;
            }
        }
        else
        {
            cout << s << tata;
        }
    }
    // 2 3 4 5
    // 1 2 3 5
    return 0;
}
