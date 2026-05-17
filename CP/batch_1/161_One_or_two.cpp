#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, two = 0, p = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 2)
            {
                two++;
            }
        }
        if (two % 2 != 0)
        {
            cout << -1 << endl;
        }
        else if (two == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 2)
                {
                    p++;
                }
                if (p == two / 2)
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}