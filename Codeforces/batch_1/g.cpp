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
        int n;
        cin >> n;
        vector<long long> a(n), c(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            y[i] = a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        int m = y.size();
        vector<long long> d1(m), d2(m);
        for (int j = 0; j < m; j++)
        {
            if (a[0] != y[j])
            {
                d1[j] = c[0];
            }
            else
            {
                d1[j] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            long long Min = d1[0];
            for (int j = 0; j < m; j++)
            {
                Min = min(Min, d1[j]);
                long long cost = (a[i] != y[j]) ? c[i] : 0;
                d2[j] = cost + Min;
            }
            d1 = d2;
        }
        long long ans = d1[0];
        for (int j = 1; j < m; j++)
        {
            ans = min(ans, d1[j]);
        }
        cout << ans << "\n";
    }
    return 0;
}