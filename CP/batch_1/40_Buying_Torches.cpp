#include <bits/stdc++.h>
using namespace std;
long long ceil_div(long long a, long long b)
{
    return (a + b - 1) / b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        cout << ceil_div(k * y + k - 1, x - 1) + k << "\n";
    }
    return 0;
}