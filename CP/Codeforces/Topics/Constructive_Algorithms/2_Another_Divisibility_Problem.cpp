// https://codeforces.com/problemset/problem/2140/B
/*
Problem: Another Divisibility Problem

Given x, construct a positive y such that concatenating x with y
is divisible by x+y.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << 2 * n << endl;
    }
    return 0;
}
