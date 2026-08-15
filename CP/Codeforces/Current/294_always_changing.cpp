#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, z = 0, o = 0, l = 1, l0 = 0, l1 = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                z++;
            }
            else
            {
                o++;
            }
        }
        if (abs(z - o) > 2)
        {
            cout << -1 << tata;
            continue;
        }
        if (s[0] == '0')
        {
            l0 = 1;
        }
        else
        {
            l1 = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                l++;
                if (s[i] == '0')
                {
                    l0++;
                }
                else
                {
                    l1++;
                }
            }
        }
        cout << n - l + max(0LL, abs(z - o - l0 + l1) - 1) << tata;
    }
    return 0;
}