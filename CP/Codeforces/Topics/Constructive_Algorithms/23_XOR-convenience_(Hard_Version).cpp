// https://codeforces.com/problemset/problem/2189/C2
/*
Problem: XOR-convenience (Hard Version)

Construct a permutation satisfying the XOR relation at every required
position, or output -1 when no such permutation exists.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define tata "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if ((n & (n - 1)) == 0)
        {
            cout << -1 << tata;
            continue;
        }
        vector<ll> v(n + 1);
        if (n % 2 != 0)
        {
            v[1] = 1;
            for (ll i = 2; i <= n; i += 2)
            {
                v[i] = i + 1;
                v[i + 1] = i;
            }
            swap(v[1], v[n]);
        }
        else
        {
            v[1] = n;
            v[n] = 1;
            for (ll i = 2; i < n; i += 2)
            {
                v[i] = i + 1;
                v[i + 1] = i;
            }
            loop(i, 2, n + 1)
            {
                if ((v[1] ^ i) <= v[1])
                {
                    swap(v[1], v[i]);
                    break;
                }
            }
        }
        loop(i, 1, n + 1)
        {
            cout << v[i] << " ";
        }
        cout << tata;
    }
    return 0;
}
