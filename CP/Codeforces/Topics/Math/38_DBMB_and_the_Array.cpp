// https://codeforces.com/problemset/problem/2193/A
/*
Problem: DBMB and the Array

Determine whether repeatedly adding x to elements of an array can make
its total sum exactly s.
*/

#include <bits/stdc++.h>
#define ll long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, s, x, sum = 0;
        cin >> n >> s >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        if (sum > s)
        {
            no;
            continue;
        }
        if ((s - sum) % x)
        {
            no;
        }
        else
        {
            yes;
        }
    }
    return 0;
}
