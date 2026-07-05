#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define tata "\n"

vector<ll> sieve(ll n)
{
    vector<ll> primes;
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (ll i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (ll i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            primes.pb(i);
        }
    }

    return primes;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> primes = sieve(n);

    for (ll p : primes)
    {
        cout << p << " ";
    }

    cout << tata;

    return 0;
}
// all primes 1 to n
// time complexity: O(n log log n)