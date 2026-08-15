// https://codeforces.com/problemset/problem/2155/A
/*
Problem: El fucho

Count the total matches played in the modified double-elimination tournament
with n teams.
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
        cout << 2 * (n - 1) << "\n";
    }
    return 0;
}
