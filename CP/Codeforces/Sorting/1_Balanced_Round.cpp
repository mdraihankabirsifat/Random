// https://codeforces.com/problemset/problem/1850/D
/*
Problem: Balanced Round

Remove as few values as possible so adjacent differences in sorted order
do not exceed k; report the number removed.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, c = 0, m = 0;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && v[i] - v[i - 1] <= k)
            {
                c++;
            }
            else
            {
                c = 1;
            }
            m = max(m, c);
        }
        cout << n - m << endl;
    }
    return 0;
}
