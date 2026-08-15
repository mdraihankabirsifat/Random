// https://codeforces.com/problemset/problem/2009/B
/*
Problem: osu!mania

Read the osu!mania grid and output the pressed column in each row
from bottom to top.
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
        char str[n][4];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> str[i][j];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                if (str[i][j] == '#')
                {
                    cout << j + 1 << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
