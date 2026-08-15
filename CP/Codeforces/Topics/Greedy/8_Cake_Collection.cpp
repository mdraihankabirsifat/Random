// https://codeforces.com/problemset/problem/2139/B
/*
Problem: Cake Collection

Cakes accumulate in ovens at fixed rates and one oven can be emptied per second.
Maximize the total cakes collected over m seconds.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, s = 0;
        cin >> n >> m;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0 && m > 0; i--)
        {
            s = s + v[i] * m;
            m--;
        }
        cout << s << endl;
    }
    return 0;
}
