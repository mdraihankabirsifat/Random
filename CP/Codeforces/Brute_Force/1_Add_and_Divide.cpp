// https://codeforces.com/problemset/problem/1485/A
/*
Problem: Add and Divide

Increment the divisor if useful, then repeatedly divide the number.
Find the minimum total number of operations needed to reduce it to zero.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, p, q, l, i, h;
        cin >> a >> b;
        l = a + 3;
        for (i = (b == 1 ? 1 : 0); i < l; i++)
        {
            q = b + i;
            p = a;
            h = i;
            while (p)
            {
                p = p / q;
                h++;
            }
            if (h < l)
            {
                l = h;
            }
        }
        cout << l << "\n";
    }
    return 0;
}
