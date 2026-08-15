// https://codeforces.com/problemset/problem/2256/A
/*
Problem: Three Numbers on the Blackboard

Given three numbers on a blackboard, compute the maximum number of
moves permitted by the balancing rule.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> v(3);
        in(v);
        sajai(v);
        cout << min(v[2] - v[0], v[1]) << tata;
    }
    return 0;
}
