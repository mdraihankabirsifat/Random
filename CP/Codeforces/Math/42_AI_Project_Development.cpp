// https://codeforces.com/problemset/problem/2233/A
/*
Problem: AI Project Development

Compute the minimum development cost or time using the two available
AI-assisted production methods and their limits.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y, z;
        cin >> n >> x >> y >> z;
        if (x * z <= n)
        {
            cout << x * z + ceil((n - x * z) / (y * 10)) << tata;
        }
        else
        {
            cout << ceil(n / x) << tata;
        }
    }
    return 0; 
}
