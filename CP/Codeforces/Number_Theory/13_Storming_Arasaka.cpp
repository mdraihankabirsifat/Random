// https://codeforces.com/problemset/problem/2238/D
/*
Problem: Storming Arasaka

Factor the given number and compute the required attack count from the
total and distinct prime factors.
*/

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
        ll n;
        cin >> n;
        vector<ll> v;
        while (n % 2 == 0)
        {
            v.pb(2);
            n /= 2;
        }
        for (ll i = 3; i * i <= n; i = i + 2)
        {
            while (n % i == 0)
            {
                v.pb(i);
                n /= i;
            }
        }
        if (n > 2)
        {
            v.pb(n);
        }
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        set<ll> s;
        for (int i = 0; i < v.size(); i++)
        {
            s.insert(v[i]);
        }
        cout << v.size() + s.size() - 1 << tata;
    }
    return 0;
}
