#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        if (l + m < 0)
        {
            cout << m * (-1) << " " << 0 << endl;
        }
        else if (r - m > 0)
        {
            cout << 0 << " " << m << endl;
        }
        else
        {
            cout << l << " " << l + m << endl;
        }
    }
    return 0;
}