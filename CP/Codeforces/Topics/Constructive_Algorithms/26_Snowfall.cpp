// https://codeforces.com/problemset/problem/2227/C
/*
Problem: Snowfall

Reorder the array to minimize the number of subarrays whose product is
divisible by 6.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
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
