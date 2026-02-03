#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, x, y, z;
        cin >> a >> b >> c;
        x = a | c;
        y = a | b;
        z = b | c;
        if ((x & y) == a && (y & z) == b && (z & x) == c)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}