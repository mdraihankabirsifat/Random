// https://codeforces.com/problemset/problem/2137/A
/*
Problem: Collatz Conjecture

Reverse k Collatz-style steps that halve an even number by repeatedly doubling x.
Output the resulting starting value.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;
        for (int i = 0; i < k; i++)
        {
            x = 2 * x;
        }
        cout << x << endl;
    }
    return 0;
}
