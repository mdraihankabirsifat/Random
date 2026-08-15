// https://codeforces.com/problemset/problem/2145/A
/*
Problem: Candies for Nephews

Find the fewest extra candies needed to make the total divisible by three,
so three nephews can receive equal shares.
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
        int n;
        cin >> n;
        if (n % 3)
        {
            cout << abs(3 - (n % 3)) << "\n";
        }
        else
        {

            cout << 0 << "\n";
        }
    }
    return 0;
}
