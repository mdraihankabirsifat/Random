// https://codeforces.com/problemset/problem/2114/C
/*
Problem: Need More Arrays

Select the maximum number of values so each next selected value is at least
two greater than the previous one.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        int last = -1, s = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] - last > 1)
            {
                s++;
                last = arr[i];
            }
        }
        cout << s << "\n";
    }
    return 0;
}
