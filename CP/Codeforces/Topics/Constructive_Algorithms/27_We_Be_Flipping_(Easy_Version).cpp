// https://codeforces.com/problemset/problem/2229/C1
/*
Problem: We Be Flipping (Easy Version)

Choose prefix-flip operations that transform the signed sequence as
required, and output a valid set of operation positions.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c = 0;
        cin >> n;
        vector<int> v(n), v1;
        in(v);
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] > 0)
            {
                ll p = 1;
                if (v[i + 1] > 0 && i != n - 1)
                {
                    p = 0;
                }
                if (p)
                {
                    c++;
                    v1.pb(i + 1);
                }
            }
            else if (v[i] < 0 && v[i + 1] > 0 && i != n - 1)
            {
                c++;
                v1.pb(i + 1);
            }
        }
        cout << c << tata;
        out(v1);
        cout << tata;
    }
    return 0;
}
