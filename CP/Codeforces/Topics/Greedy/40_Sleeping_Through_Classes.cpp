// https://codeforces.com/problemset/problem/2173/A
/*
Problem: Sleeping Through Classes

Choose the maximum number of periods to sleep through while respecting
the k-period restriction after each mandatory class.
*/

#include <bits/stdc++.h>
#define ll long long
#define tata '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, c = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        loop(i, n)
        {
            if (s[i] == '1')
            {
                ll m = i;
                for (int j = m + 1; j <= m + k; j++)
                {
                    i++;
                    if (s[j] == '1')
                    {
                        i--;
                        break;
                    }
                    else if (j == n)
                    {
                        break;
                    }
                }
            }
            else
            {
                c++;
            }
        }
        cout << c << tata;
    }
    return 0;
}
