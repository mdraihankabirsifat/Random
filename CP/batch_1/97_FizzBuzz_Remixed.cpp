#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 3)
        {
            cout << n + 1 << endl;
        }
        else
        {
            int ans = ((n / 15) + 1) * 3;
            if ((n - (n / 15) * 15) < 3)
            {
                ans = ans + n - (n / 15) * 15 - 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}