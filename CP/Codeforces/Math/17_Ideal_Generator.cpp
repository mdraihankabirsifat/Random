// https://codeforces.com/problemset/problem/2093/A
/*
Problem: Ideal Generator

Determine whether the given number can be generated as a sum of an odd
count of odd integers under the stated conditions.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
