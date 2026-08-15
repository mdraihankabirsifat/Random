// https://codeforces.com/problemset/problem/2197/A
/*
Problem: Friendly Numbers

For a given x, count integers y satisfying y minus its digit sum equals
x.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define tata "\n"
using namespace std;

ll sum(ll n)
{
    ll s = 0;
    while (n)
    {
        s = s + (n % 10);
        n = n / 10;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, f = 0;
        cin >> n;
        loop(i, n, n + 81)
        {
            if (i - sum(i) == n)
            {
                cout << 10 << tata;
                f = 1;
                break;
            }
        }
        if (!f)
        {
            cout << 0 << tata;
        }
    }
    return 0;
}
