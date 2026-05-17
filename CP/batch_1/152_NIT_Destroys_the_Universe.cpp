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
        long long n, f = 0, s = 0;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s = s + v[i];
            if (v[i] == 0 && f == 0)
            {
                v[i] = -1;
            }
            else
            {
                f = 1;
            }
        }
        if (s == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            f = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (v[i] == 0 && f == 0)
                {
                    v[i] = -1;
                }
                else
                {
                    f = 1;
                }
            }
            f = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                {
                    cout << 2 << endl;
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}