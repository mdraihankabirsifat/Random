// https://codeforces.com/problemset/problem/1559/A
/*
Problem: Mocha and Math

Apply bitwise AND across the entire array to obtain the minimum possible result.
undefined
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
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long a = v[0];
        for (int i = 1; i < n; i++)
        {
            a = a & v[i];
        }
        cout << a << "\n";
    }
    return 0;
}
