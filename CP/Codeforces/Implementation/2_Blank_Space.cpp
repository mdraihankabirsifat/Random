// https://codeforces.com/problemset/problem/1829/B
/*
Problem: Blank Space

Find the maximum number of consecutive zeros in each binary array.
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
        int n, s = 0, temp = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 0)
            {
                s++;
            }
            else
            {
                s = 0;
            }
            if (s > temp)
            {
                temp = s;
            }
        }
        cout << temp << endl;
    }
    return 0;
}
