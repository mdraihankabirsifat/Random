#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define tata "\n"
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

bool prime(ll n)
{
    if (n < 2)
    {
        return false;
    }

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    prime(n) ? yes : no;

    return 0;
}