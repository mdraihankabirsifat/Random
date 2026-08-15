// https://codeforces.com/problemset/problem/2228/B
/*
Problem: Remilia Plays Soku

Compute the minimum game value or distance on a cyclic arena from the
two starting positions and the supplied modifier.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        if (n == 2 || n == 3)
        {
            cout << 1 << tata;
        }
        else
        {
            cout << min(n - abs(x1 - x2), abs(x1 - x2)) + k << tata;
        }
    }
    return 0;
}
