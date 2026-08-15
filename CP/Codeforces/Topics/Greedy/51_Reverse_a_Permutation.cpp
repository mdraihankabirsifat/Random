// https://codeforces.com/problemset/problem/2193/B
/*
Problem: Reverse a Permutation

Reverse at most one contiguous segment of a permutation to obtain the
lexicographically largest possible permutation.
*/

#include <bits/stdc++.h>
#define ll long long
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
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
        vector<ll> v(n), p(n);
        in(v);
        p = v;
        sort(p.begin(), p.end(), greater<ll>());
        // out(p);
        // cout << tata;
        for (int i = 0; i < n; i++)
        {
            if (p[i] != v[i])
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (v[j] == p[i])
                    {
                        reverse(v.begin() + i, v.begin() + j + 1);
                        goto end;
                    }
                }
            }
        }
    end:;
        out(v);
        cout << tata;
    }
    return 0;
}
