// https://codeforces.com/problemset/problem/2196/A
/*
Problem: Game with a Fraction

Alice and Bob decrement the numerator or denominator of a fraction;
determine the winner under optimal play around the value 2/3.
*/

#include <bits/stdc++.h>
#define ll long long
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
        ll a, b;
        cin >> a >> b;
        ll p = 3 * a - 2 * b;
        if (p < 0)
        {
            cout << "Alice" << tata;
        }
        else if (p >= min(a, b))
        {
            cout << "Alice" << tata;
        }
        else
        {
            cout << "Bob" << tata;
        }
    }
    return 0;
}
