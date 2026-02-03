#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if (x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        if (a > x && a < y)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
    return 0;
}