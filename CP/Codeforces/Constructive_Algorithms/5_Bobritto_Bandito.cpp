// https://codeforces.com/problemset/problem/2094/B
/*
Problem: Bobritto Bandito

Given the current infected interval and elapsed days, construct any interval
that could have been infected after the requested earlier number of days.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        if (l + m < 0)
        {
            cout << m * (-1) << " " << 0 << endl;
        }
        else if (r - m > 0)
        {
            cout << 0 << " " << m << endl;
        }
        else
        {
            cout << l << " " << l + m << endl;
        }
    }
    return 0;
}
