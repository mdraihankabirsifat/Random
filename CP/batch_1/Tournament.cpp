#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> v(n);
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (max < v[i])
            {
                max = v[i];
            }
        }
        if (k >= 2)
        {
            cout << "YES" << endl;
        }
        else if (k == 1 && max == v[j-1])
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