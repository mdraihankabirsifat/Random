// https://codeforces.com/problemset/problem/2195/B
/*
Problem: Heapify 1

Given a permutation stored as a heap, decide whether values can be
rearranged along doubling-index chains to restore the required heap.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define sajai(x) sort(x.begin(), x.end())
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

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
        vr(v, n + 1);
        vector<ll> p(n + 1), v2(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }
        v2 = v;
        for (int i = 1; i <= n; i++)
        {
            if (!p[i])
            {
                vector<ll> g, h;
                for (int j = i; j <= n; j = 2 * j)
                {
                    g.pb(v[j]);
                    h.pb(j);
                    p[j] = 1;
                }
                sajai(g);
                sajai(h);
                if (g != h)
                {
                    no;
                    goto end;
                }
            }
        }
        yes;
    end:;
    }
    return 0;
}
