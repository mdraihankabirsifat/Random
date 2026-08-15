// https://codeforces.com/problemset/problem/2110/A
/*
Problem: Fashionable Array

Remove the fewest elements so the remaining array's minimum and maximum
have an even sum.
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
    }
    return 0;
}
