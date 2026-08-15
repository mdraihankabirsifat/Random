// https://codeforces.com/problemset/problem/2084/A
/*
Problem: Max and Mod

Construct the required permutation satisfying the maximum-and-modulo conditions,
or print -1 when no valid permutation exists.
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
            cout << "-1" << endl;
        }
        else if(n>2)
        {
            cout << n << " 1 ";
            for (int i = 2; i < n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
