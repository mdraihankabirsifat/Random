// https://codeforces.com/problemset/problem/2070/A
/*
Problem: FizzBuzz Remixed

Count integers from zero through n whose remainders modulo 3 and 5 are equal.
undefined
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
        if (n < 3)
        {
            cout << n + 1 << endl;
        }
        else
        {
            int ans = ((n / 15) + 1) * 3;
            if ((n - (n / 15) * 15) < 3)
            {
                ans = ans + n - (n / 15) * 15 - 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
