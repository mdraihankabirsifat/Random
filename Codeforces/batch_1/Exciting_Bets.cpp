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
        long long a, b, c;
        cin >> a >> b;
        c = abs(a - b);
        if (a == b)
            cout << 0 << " " << 0 << "\n";
        else
            cout << c << " " << min((a % c), (c * (a / c + 1) - a)) << "\n";
    }
    return 0;
}