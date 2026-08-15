// https://codeforces.com/problemset/problem/2238/B
/*
Problem: Crimson Triples

Count the Crimson triples determined by the divisibility relationships
among integers up to n.
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
        ll n, s = 0;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            s = s + pow(floor(n / i), 2);
        }
        cout << s+1 << tata;
    }
    return 0;
}
