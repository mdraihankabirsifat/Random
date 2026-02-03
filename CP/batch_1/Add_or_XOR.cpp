#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a == b)
        {
            cout << 0 << endl;
        }
        else if (a < b)
        {
            int cost1 = (b - a) * x;
            int curr = a, cost2 = 0;
            while (curr < b)
            {
                if (curr % 2 == 0)
                {
                    curr ^= 1; //if even then X-OR
                    cost2 += y;
                }
                else
                {
                    curr += 1;
                    cost2 += x;
                }
            }
            cout << min(cost1, cost2) << endl;
        }
        else
        {
            int cost = 0;
            bool possible = true;
            while (a > b)
            {
                if (a % 2 == 1)
                {
                    a ^= 1;
                    cost += y;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            if (a == b && possible)
                cout << cost << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}