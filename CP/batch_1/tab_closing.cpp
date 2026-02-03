#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        if ((b * n <= a) || (a == b))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 2 << "\n";
        }
    }
    return 0;
}