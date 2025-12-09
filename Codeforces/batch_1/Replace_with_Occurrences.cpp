#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, f = 0;
        cin >> n;
        vector<int> v(n), p(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            p[v[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (p[i] % i != 0 && p[i] != 0)
            {
                cout << -1 << endl;
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            int j;
            for (int i = 0; i < n; i++)
            {
                for (j = 0; j < v[i]; j++)
                {
                    cout << i + 1 << " ";
                }
                i = i + j - 1;
            }
            cout << endl;
        }
    }
    return 0;
}