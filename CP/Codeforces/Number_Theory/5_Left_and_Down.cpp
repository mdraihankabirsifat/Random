// https://codeforces.com/problemset/problem/2125/B
/*
Problem: Left and Down

Reach (a,b) using repeated bounded left/down step vectors and minimize
the number of distinct vectors required.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, k;
        cin >> a >> b >> k;
        if (k >= a && k >= b)
        {
            cout << 1 << endl;
            continue;
        }
        long long g = __gcd(a, b);
        if (a / g <= k && b / g <= k)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}
