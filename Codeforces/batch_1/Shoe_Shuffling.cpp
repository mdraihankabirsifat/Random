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
        int n, c = 1, f = 0;
        cin >> n;
        vector<long long> v(n), p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int j;
        for (int i = 0; i < n; i++)
        {
            c = 1;
            for (j = i + 1; j < n; j++)
            {
                if (v[i] == v[j])
                {
                    c++;
                }
                else
                {
                    break;
                }
            }
            j--;
            if (c > 1)
            {
                p[i] = j + 1;
                for (int k = i + 1; k <= j; k++)
                {
                    p[k] = k;
                }
            }
            else
            {
                f = 1;
                cout << -1 << "\n";
                break;
            }
            i = j;
        }
        if (f == 0)
        {
            for (int i = 0; i < n; i++)
            {
                cout << p[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}