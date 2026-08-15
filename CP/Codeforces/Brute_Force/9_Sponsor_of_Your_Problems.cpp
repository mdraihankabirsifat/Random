// https://codeforces.com/problemset/problem/2121/E
/*
Problem: Sponsor of Your Problems

Choose an integer between l and r minimizing its total digit matches
with both interval endpoints.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, digit = 0, i = 1, c = 0;
        cin >> l >> r;
        int x = l;
        while (x != 0)
        {
            x = x / 10;
            digit++;
        }
        while (i <= digit)
        {
            int j = (l / (int)pow(10, (digit - i))) % 10;
            int h = (r / (int)pow(10, (digit - i))) % 10;
            if (abs(j - h) < 2)
            {
                c++;
            }
            i++;
        }
        cout << 2 * c << "\n";
    }
    return 0;
}
