#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, r = 0;
        cin >> n >> k;
        if (k == 1 && (n % 2) == 0)
        {
            r = 1;
        }
        else if (k > 1 && (n % 2 != 0))
        {
            if ((k % 4) == 3)
            {
                r = 1;
            }
            else if ((k % 4) == 0)
            {
                r = 1;
            }
        }
        else if (k > 3 && (n % 2 == 0))
        {
            if ((k % 4) == 1)
            {
                r = 1;
            }
            else if ((k % 4) == 0)
            {
                r = 1;
            }
        }
        if (r)
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