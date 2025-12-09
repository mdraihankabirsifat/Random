#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c, k = 0;
        cin >> n >> c;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = n-1; i >= 0; i--)
        {
            if (v[i] * pow(2, k) <= c)
            {
                k++;
            }
        }
        cout << n - k << endl;
    }
    return 0;
}