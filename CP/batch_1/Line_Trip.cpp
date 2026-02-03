#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, i, j = 0, b = -1, temp = -1;
        cin >> n >> x;
        vector<int> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        i = 0;
        while (j <= n)
        {
            if (j == n)
            {
                b = 2 * (x - v[n - 1]);
            }
            else
            {
                b = v[j] - i;
                i = v[j];
            }
            j++;
            if (temp < b)
            {
                temp = b;
            }
        }
        cout << temp << endl;
    }
    return 0;
}