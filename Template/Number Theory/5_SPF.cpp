#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

const ll N = 1000000 + 5;

vector<ll> spf(N);

void buildSPF()
{
    for (ll i = 1; i < N; i++)
    {
        spf[i] = i;
    }

    for (ll i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<ll> getFactors(ll n)
{
    vector<ll> factors;

    while (n != 1)
    {
        factors.pb(spf[n]);
        n /= spf[n];
    }

    return factors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    buildSPF();

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> factors = getFactors(n);

        for (ll x : factors)
        {
            cout << x << " ";
        }

        cout << tata;
    }

    return 0;
}