// https://codeforces.com/problemset/problem/2090/A
/*
Problem: Treasure Hunt

Two players alternately dig fixed amounts x and y; determine who makes
the cumulative depth exceed the target a first.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, a;
        cin >> x >> y >> a;
        long long s = a % (x + y);
        if (s < x)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
