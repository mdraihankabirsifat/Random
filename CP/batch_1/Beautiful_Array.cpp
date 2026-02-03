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
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        long long p = k * (b + 1) - 1;
        if (s < b * k || s > (b * k + n * (k - 1)))
        {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (s >= p)
            {
                if (i == 0)
                {
                    cout << p << " ";
                }
                else
                {
                    cout << k - 1 << " ";
                }
            }
            else
            {
                if (i == 0)
                {
                    cout << s << " ";
                }
                else if (p - k + 1 < s)
                {
                    cout << s - p + k - 1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            p = p + k - 1;
        }
        cout << "\n";
    }
    return 0;
}