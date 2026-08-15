// https://codeforces.com/problemset/problem/2118/A
/*
Problem: Equal Subsequences

Construct a binary string of length n whose selected subsequences satisfy
the required equality, using exactly k leading choices.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++)
        {
            cout << 1;
        }
        for (int i = 0; i < n - k; i++)
        {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
