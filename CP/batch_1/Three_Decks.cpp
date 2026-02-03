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
        long long a, b, c, s;
        cin >> a >> b >> c;
        if ((a + b + c) % 3 == 0)
        {
            s = (a + b + c) / 3;
            if (a > s || b > s)
            {
                cout << "NO" << "\n";
            }
            else
            {
                cout << "YES" << "\n";
            }
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}