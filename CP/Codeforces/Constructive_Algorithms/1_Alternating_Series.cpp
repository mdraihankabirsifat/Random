// https://codeforces.com/problemset/problem/2131/B
/*
Problem: Alternating Series

Construct the lexicographically best absolute-value sequence whose signs alternate
and whose every subarray of length at least two has positive sum.
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
        if (n == 2)
        {
            cout << "-1 2" << endl;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (n % 2 == 0 && i == n)
                {
                    cout << "2 ";
                }
                else if (i % 2 != 0)
                {
                    cout << "-1 ";
                }
                else
                {
                    cout << "3 ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
