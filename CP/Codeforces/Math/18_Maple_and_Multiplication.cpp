// https://codeforces.com/problemset/problem/2139/A
/*
Problem: Maple and Multiplication

Make two positive integers equal by multiplying either number by an integer.
Find the minimum number of operations.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
        }
        else if (a % b == 0 || b % a == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}
