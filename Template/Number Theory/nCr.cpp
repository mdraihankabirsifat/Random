#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tata "\n"

const ll MOD = 1000000007;
const ll N = 1000000 + 5;

ll fact[N];
ll invFact[N];

ll power(ll a, ll b)
{
    ll res = 1;

    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

void precompute()
{
    fact[0] = 1;

    for (ll i = 1; i < N; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[N - 1] = power(fact[N - 1], MOD - 2);

    for (ll i = N - 1; i >= 1; i--)
    {
        invFact[i - 1] = invFact[i] * i % MOD;
    }
}

ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
    {
        return 0;
    }

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    ll n, r;
    cin >> n >> r;

    cout << nCr(n, r) << tata;

    return 0;
}