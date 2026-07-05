#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

vector<pair<ll, ll>> primeFactorization(ll n)
{
    vector<pair<ll, ll>> factors;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;

            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }

            factors.pb({i, cnt});
        }
    }

    if (n > 1)
    {
        factors.pb({n, 1});
    }

    return factors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> factors = primeFactorization(n);

    for (auto x : factors)
    {
        cout << x.first << "^" << x.second << tata;
    }

    return 0;
}