// https://codeforces.com/problemset/problem/1855/B
/*
Problem: Longest Divisors Interval

Find the longest consecutive interval of positive integers in which every
integer divides n.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, i = 1;
        cin >> n;
        while (n % i == 0)
        {
            i++;
        }
        cout << i - 1 << endl;
    }
    return 0;
}
