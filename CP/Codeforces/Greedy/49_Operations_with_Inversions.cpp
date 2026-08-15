// https://codeforces.com/problemset/problem/2176/A
/*
Problem: Operations with Inversions

Apply the permitted operation to eliminate every inversion in an array
and determine the minimum number of affected elements.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define tata "\n"
using namespace std;

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
        vector<int> v(n);
        in(v);
        loop(i, 0, n - 1)
        {
            loop(j, i + 1, n)
            {
                if (v[i] > v[j] && v[j] != -1)
                {
                    c++;
                    v[j] = -1;
                }
            }
        }
        cout << c << tata;
    }
    return 0;
}
