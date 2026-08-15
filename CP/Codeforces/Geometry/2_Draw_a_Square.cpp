// https://codeforces.com/problemset/problem/2074/A
/*
Problem: Draw a Square

Given distances left, right, down, and up from the origin, determine
whether the four points form an axis-aligned square.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        if (l == r && r == d && d == u)
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
