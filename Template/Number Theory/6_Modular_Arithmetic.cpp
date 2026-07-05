#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

const ll MOD = 1e9 + 7;

ll modAdd(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    b %= mod;

    return (a + b) % mod;
}

ll modSub(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    b %= mod;

    return (a - b + mod) % mod;
}

ll modMul(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    b %= mod;

    return (a * b) % mod;
}

ll binpow(ll a, ll b, ll mod = MOD)
{
    a %= mod;

    ll ans = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            ans = modMul(ans, a, mod);
        }

        a = modMul(a, a, mod);
        b >>= 1;
    }

    return ans;
}

ll modInverse(ll a, ll mod = MOD)
{
    return binpow(a, mod - 2, mod);
}

ll modDiv(ll a, ll b, ll mod = MOD)
{
    return modMul(a, modInverse(b, mod), mod);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    cout << "Add = " << modAdd(a, b) << tata;
    cout << "Sub = " << modSub(a, b) << tata;
    cout << "Mul = " << modMul(a, b) << tata;
    cout << "Power = " << binpow(a, b) << tata;
    cout << "Inverse of a = " << modInverse(a) << tata;

    return 0;
}