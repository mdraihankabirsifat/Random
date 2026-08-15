// https://codeforces.com/problemset/problem/2074/B
/*
Problem: The Third Side

Repeatedly combine two sides to create a valid third side, and determine
the final remaining side length after reducing the whole collection.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s = s + v[i];
        }
        cout << s - (n - 1) << endl;
    }
    return 0;
}
