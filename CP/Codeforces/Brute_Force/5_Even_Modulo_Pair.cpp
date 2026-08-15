// https://codeforces.com/problemset/problem/2164/B
/*
Problem: Even Modulo Pair

Find two array values a_i and a_j such that (a_j mod a_i) is even,
or print -1 if no such pair exists.
*/

#include <bits/stdc++.h>
#define ll long long
#define tata '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define in(v) loop(i, v.size()) cin >> v[i]
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
        vector<ll> v(n);
        in(v);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((v[j] % v[i]) % 2 == 0)
                {
                    cout << v[i] << " " << v[j] << tata;
                    goto end;
                }
            }
        }
        cout << -1 << tata;
    end:;
    }
    return 0;
}
