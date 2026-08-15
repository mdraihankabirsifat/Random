// https://codeforces.com/problemset/problem/2121/C
/*
Problem: Those Who Are With Us

Choose one row and one column of a matrix and decrement their union
by one so that the largest remaining matrix value is minimized.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, max = 0, c = 0, r = 0;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                if (v[i][j] > max)
                {
                    max = v[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == max)
                {
                    
                }
            }
        }
    }
    return 0;
}
