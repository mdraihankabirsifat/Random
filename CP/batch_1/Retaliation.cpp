#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m = 0, c = 1;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] > m)
            {
                m = v[i];
            }
            if (i > 0)
            {
                if (v[i] == v[i - 1])
                {
                    c++;
                }
            }
        }
        if (c == n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == m)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 2 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}