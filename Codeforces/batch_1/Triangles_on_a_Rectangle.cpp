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
        long long w, h, y = 0, x = 0, m1, m2;
        cin >> w >> h;
        int l = 4;
        while (l--)
        {
            y = x;
            int n;
            cin >> n;
            vector<int> v(n);
            for (int i = 0; i < n; i++)
            {
                cin >> v[i];
            }
            if (l == 3)
            {
                x = (v[n - 1] - v[0]) * h;
            }
            else if (l == 2)
            {
                x = (v[n - 1] - v[0]) * h;
                m1 = max(y, x);
                y = 0;
                x = 0;
            }
            else if (l == 1)
            {
                x = (v[n - 1] - v[0]) * w;
            }
            else if (l == 0)
            {
                x = (v[n - 1] - v[0]) * w;
                m2 = max(y, x);
            }
        }
        cout << max(m1, m2) << "\n";
    }
    return 0;
}