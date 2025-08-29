#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y)
{
    double max = 0, min = 0;
    max = (x > y) ? x : y;
    min = (x < y) ? x : y;
    if (min >= ceil(max / 2) - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = check(a, b);
        int f = check(c - a, d - b);
        if (s * f)
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