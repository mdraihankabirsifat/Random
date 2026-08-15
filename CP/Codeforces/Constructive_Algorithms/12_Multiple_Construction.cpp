// https://codeforces.com/problemset/problem/2147/B
/*
Problem: Multiple Construction

Construct a length-2n sequence using each value with the required
multiplicative relationship between its two occurrences.
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
        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << n << " ";
        for (int i = 1; i < n; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
