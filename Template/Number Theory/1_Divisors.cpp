#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

vector<ll> getDivisors(ll n)
{
    vector<ll> divisors;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.pb(i);

            if (i != n / i)
            {
                divisors.pb(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    return divisors;
}

ll countDivisors(ll n)
{
    ll cnt = 0;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;

            if (i != n / i)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

ll sumDivisors(ll n)
{
    ll sum = 0;

    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;

            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> divisors = getDivisors(n);

    for (ll x : divisors)
    {
        cout << x << " ";
    }
    cout << tata;

    cout << "Count = " << countDivisors(n) << tata;
    cout << "Sum = " << sumDivisors(n) << tata;

    return 0;
}