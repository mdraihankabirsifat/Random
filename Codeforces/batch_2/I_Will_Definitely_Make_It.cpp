#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, t = 0, y, x = 0, temp = 0;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            y = v[k - 1];
        }
        sort(v.begin(), v.end());
        int m = *max_element(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (v[i] == y)
            {
                t = 1;
            }
            if (t == 1)
            {
                if (v[i] != m && v[i + 1] - v[i] <= v[i] - x)
                {
                    x = x + v[i + 1] - v[i];
                }
                else if (v[i] != m && v[i + 1] - v[i] > v[i] - x)
                {
                    cout << "NO" << endl;
                    temp = 1;
                    break;
                }
            }
        }
        if (temp == 0)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}