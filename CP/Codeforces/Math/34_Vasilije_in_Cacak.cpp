// https://codeforces.com/problemset/problem/1878/C
/*
Problem: Vasilije in Cacak

Determine whether k distinct integers from 1 through n can have sum x
by comparing x with the minimum and maximum achievable sums.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        if (x >= (k * (k + 1) / 2) && x <= ((n * (n + 1) / 2) - ((n - k) * (n - k + 1) / 2)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
