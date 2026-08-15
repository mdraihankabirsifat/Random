// https://codeforces.com/problemset/problem/2241/A
/*
Problem: Divide and Conquer

Determine whether a can be divided into equal groups of size b under
the problem's divide-and-conquer operation.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
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
        ll a, b;
        cin >> a >> b;
        if (a % b)
            no;
        else
            yes;
    }
    return 0;
}
