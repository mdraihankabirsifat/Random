// https://codeforces.com/problemset/problem/2210/A
/*
Problem: A Simple Sequence

Construct a length-n permutation satisfying the problem's required
simple-sequence property.
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
        ll n;
        cin >> n;
        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << tata;
    }
    return 0;
}
