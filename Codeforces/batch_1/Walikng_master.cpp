#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b <= d && c - a <= d - b)
        {
            cout << 2 * (d - b) + (a - c) << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}