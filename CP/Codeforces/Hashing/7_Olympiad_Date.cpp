// https://codeforces.com/problemset/problem/2091/A
/*
Problem: Olympiad Date

Find the earliest prefix of drawn digits that can form the date 01.03.2025,
or output zero if it never becomes possible.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp = 0, c0 = 0, c1 = 0, c2 = 0, c5 = 0, c3 = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
                c0++;
            else if (v[i] == 1)
                c1++;
            else if (v[i] == 2)
                c2++;
            else if (v[i] == 3)
                c3++;
            else if (v[i] == 5)
                c5++;
            if (c0 >= 3 && c1 >= 1 && c2 >= 2 && c3 >= 1 && c5 >= 1)
            {
                cout << i + 1 << endl;
                temp = 1;
                break;
            }
        }
        if (temp == 0)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
