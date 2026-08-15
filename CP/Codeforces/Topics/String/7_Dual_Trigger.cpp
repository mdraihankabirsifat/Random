// https://codeforces.com/problemset/problem/1951/A
/*
Problem: Dual Trigger

Determine whether paired bit-trigger operations can turn every bit of the
binary string off.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 0, m = 0;
        cin >> n;
        string s;
        cin >> s;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = s[i] - '0';
            if (v[i] == 1)
            {
                c++;
            }
            if (i > 0)
            {
                if (v[i] == 1 && v[i] == v[i - 1])
                {
                    m++;
                }
            }
        }
        if (c == 2 && m == 1)
        {
            cout << "NO" << endl;
        }
        else if (c % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
