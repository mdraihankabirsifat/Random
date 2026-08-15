// https://codeforces.com/problemset/problem/2158/A
/*
Problem: Suspension

Compute the number of suspended participants from the yellow and red card
counts, capped by the total number of players.
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, y, r;
        cin >> n;
        cin >> y >> r;
        ll p = r + y / 2;
        if (p > n)
        {
            cout << n << endl;
        }
        else
        {
            cout << p << endl;
        }
    }
    return 0;
}
