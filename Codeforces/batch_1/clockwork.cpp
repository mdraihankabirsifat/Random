#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        int temp = 1;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            if (v[i - 1] <= max(2 * (i - 1), 2 * (n - i)))
            {
                temp = 0;
                break;
            }
        }
        if (temp)
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