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
        long long a, b;
        cin >> a >> b;
        if (a < b)
        {
            cout << 2 << "\n";
        }
        else
        {
            if (a >= b + 2 && b != 1)
            {
                cout << 3 << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}