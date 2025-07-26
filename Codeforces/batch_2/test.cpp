#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp = 1;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                if (v[0] <= 2 * (n - i))
                {
                    cout << "NO" << endl;
                    temp = 0;
                    break;
                }
            }
            else if (i == n)
            {
                if (v[n - 1] <= 2 * (i - 1))
                {
                    cout << "NO" << endl;
                    temp = 0;
                    break;
                }
            }
            else if (v[i - 1] <= min(2 * (i - 1), 2 * (n - i)))
            {
                cout << "NO" << endl;
                temp = 0;
                break;
            }
        }
        if (temp)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}