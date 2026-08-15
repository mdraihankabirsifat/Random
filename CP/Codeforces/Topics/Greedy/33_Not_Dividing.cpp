// https://codeforces.com/problemset/problem/1794/B
/*
Problem: Not Dividing

Increase array elements so no element is divisible by the preceding element,
then output any valid resulting array.
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
        int n, k = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 1)
            {
                v[i] = 2;
            }
            if (i > 0)
            {
                if (v[i] % v[i - 1] == 0)
                {
                    v[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
