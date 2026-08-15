// https://codeforces.com/problemset/problem/1900/A
/*
Problem: Cover in Water

Fill all empty cells with water using the minimum number of direct placements,
taking advantage of a run of at least three empty cells.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, dot = 0, temp = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (i > 1 && s[i] == '.' && s[i - 1] == '.' && s[i - 2] == '.')
            {
                temp = 1;
            }
            if (s[i] == '.')
            {
                dot++;
            }
        }
        if (temp == 0)
        {
            cout << dot << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}
