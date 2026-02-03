#include <bits/stdc++.h>
using namespace std;
long long x_or(long long p, int n, vector<long long> v)
{
    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + ((~p & v[i]) | (~v[i] & p));
    }
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long m = 0;
        for (int i = 0; i < n; i++)
        {
            long long temp = m;
            m = x_or(v[i], n, v);
            if (m < temp)
            {
                m = temp;
            }
        }
        cout << m << endl;
    }
    return 0;
}
// time limit exceed