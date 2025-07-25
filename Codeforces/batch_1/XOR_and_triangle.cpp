#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y = 0, c = -1;
        cin >> x;
        for (int i = 0; i <= 30; i++)
        {
            for (int j = 0; j <= 30; j++)
            {
                y = (1 << i) | (1 << j);
                if (y < x && x + y > (x ^ y) && (x ^ y) + y > x)
                {
                    c = y;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}