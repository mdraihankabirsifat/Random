// https://codeforces.com/problemset/problem/486/A
/*
Problem: Calculating Function

Evaluate the alternating signed sum from 1 through n, where odd terms
are subtracted and even terms are added.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << endl;
    }
    else
    {
        cout << -(n + 1) / 2 << endl;
    }
    return 0;
}
