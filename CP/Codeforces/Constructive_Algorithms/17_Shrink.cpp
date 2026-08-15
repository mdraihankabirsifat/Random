// https://codeforces.com/problemset/problem/2117/B
/*
Problem: Shrink

Construct a permutation whose adjacent elements never differ by one,
or output an appropriate arrangement for the given n.
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
        cout << "1" << " ";
        for (int i = 3; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << "2\n";
    }
    return 0;
}
