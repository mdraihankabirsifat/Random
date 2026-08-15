// https://codeforces.com/problemset/problem/2126/D
/*
Problem: This Is the Last Time

Starting with k coins, visit each casino at most once when its allowed
coin interval contains your balance, and maximize the final balance.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> v[i][j];
            }
        }
    }
    return 0;
}
