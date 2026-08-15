// https://codeforces.com/problemset/problem/2137/C
/*
Problem: Maximum Even Sum

Choose a divisor-based redistribution between a and b that makes their sum even.
Output the maximum achievable even sum, or -1.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (b % 2 != 0)
        {
            if (a % 2 == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << a * b + 1 << endl;
            }
        }
        else
        {
            if ((b / 2) % 2 != 0 && a % 2 != 0)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << a * b / 2 + 2 << endl;
            }
        }
    }
    return 0;
}
