// https://codeforces.com/problemset/problem/2165/A
/*
Problem: Cyclic Merging

Repeatedly merge adjacent values on a cycle according to the stated cost.
Compute the minimum total cost to reduce the cycle to one value.
*/

#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, s = 0;
        cin >> n;
        vector<ll> v(n + 1);
        loop(i, n)
        {
            cin >> v[i];
        }
        v[n] = v[0];
        loop(i, n)
        {
            s += max(v[i], v[i + 1]);
        }
        cout << s - *max_element(v.begin(), v.end()) << endl;
    }
    return 0;
}
