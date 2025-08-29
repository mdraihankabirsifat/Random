#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 2, b = -1, a1 = 0, b1 = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] != v[0])
            {
                b = v[i];
            }
            if (v[i] == v[0])
            {
                a1++;
            }
            if (v[i] == b)
            {
                b1++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] != v[0] && v[i] != b)
            {
                c++;
            }
        }
        if (a1 == n || (c == 2 && (a1 == b1 || a1 == b1 + 1 || a1 == b1 - 1)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}