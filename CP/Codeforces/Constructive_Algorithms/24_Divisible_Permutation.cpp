// https://codeforces.com/problemset/problem/2188/A
/*
Problem: Divisible Permutation

Construct a permutation of 1 through n satisfying the required
divisibility condition between its positions and values.
*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
using namespace std;

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
        vector<ll> v;
        ll p = ceil((double)n / 2);
        for (int i = 1; i <= p; i++)
        {
            if (i == p && n % 2)
            {
                v.pb(i);
                break;
            }
            v.pb(i);
            v.pb(n - i + 1);
        }
        reverse(v.begin(), v.end());
        out(v);
    }
    return 0;
}
