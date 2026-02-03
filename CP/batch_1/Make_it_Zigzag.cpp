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
        long long n, c = 0, m = -1;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (v[0] >= v[1])
        {
            c++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            m = max(m, v[i]);
            if (i % 2 && m <= v[i + 1])
            {
                c = c + v[i + 1] - m + 1;
            }
        }
        cout << c << "\n";
    }
    return 0;
}