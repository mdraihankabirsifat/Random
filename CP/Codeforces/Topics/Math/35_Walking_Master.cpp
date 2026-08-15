// https://codeforces.com/problemset/problem/1806/A
/*
Problem: Walking Master

Move from one lattice point using allowed upward-diagonal and left moves;
find the minimum moves required, or report that it is impossible.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b <= d && c - a <= d - b)
        {
            cout << 2 * (d - b) + (a - c) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
