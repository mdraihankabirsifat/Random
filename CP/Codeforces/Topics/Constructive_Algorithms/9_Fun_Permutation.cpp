// https://codeforces.com/problemset/problem/2137/B
/*
Problem: Fun Permutation

Given a permutation p, construct a permutation q so corresponding entries
combine to the same constant value.
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
            cout << n - v[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
