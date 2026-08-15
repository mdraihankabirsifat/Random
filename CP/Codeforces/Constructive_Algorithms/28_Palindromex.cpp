// https://codeforces.com/problemset/problem/2227/D
/*
Problem: Palindromex

Split the given value into two valid Palindromex values, or report
that no valid decomposition exists.
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
        ll a;
        cin >> a;
        ll p = a / 12;
        ll r = a % 12;
        if (r == 10)
        {
            if (a < 22)
            {
                cout << -1 << tata;
            }
            else
            {
                cout << 22 << " " << a - 22 << tata;
            }
        }
        else
        {
            cout << a - p * 12 << " " << p * 12 << tata;
        }
    }
    return 0;
}
