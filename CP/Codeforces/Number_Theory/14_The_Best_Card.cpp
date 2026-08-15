// https://codeforces.com/problemset/problem/2253/A
/*
Problem: The Best Card

Determine whether the numbered card is best by testing the required
prime condition on the next integer.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

bool prime(ll n)
{
    if (n < 2)
        return false;

    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

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
        if (prime(n + 1))
        {
            yes;
        }
        else
        {
            no;
        }
    }
    return 0;
}
