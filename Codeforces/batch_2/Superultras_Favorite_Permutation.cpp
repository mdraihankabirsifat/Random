#include <bits/stdc++.h>
using namespace std;
int prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 1;
            break;
        }
    }
    return 0;
}
int main()
{
    int t, v;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 5)
        {
            cout << -1 << endl;
        }
        else
        {
            int i, j;
            for (i = 2; i <= n; i = i + 2)
            {
                cout << i << " ";
            }
            i = i - 2;
            for (j = 1; j < 8; j = j + 2)
            {
                int x = prime(i + j);
                if (x == 1)
                {
                    break;
                }
            }
            for (int k = j; k <= n; k = k + 2)
            {
                cout << k << " ";
            }
            for (int h = 1; h < j; h = h + 2)
            {
                cout << h << " ";
            }
            cout << endl;
        }
    }
    return 0;
}