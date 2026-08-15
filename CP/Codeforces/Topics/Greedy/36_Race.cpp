// https://codeforces.com/problemset/problem/2112/A
/*
Problem: Race

Choose a different integer starting point and determine whether it can be
strictly closer than a to both target points x and y.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if (x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        if (a > x && a < y)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    return 0;
}
