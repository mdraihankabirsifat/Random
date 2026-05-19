#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b, p = 0, r = 0, f = 1;
        cin >> n >> a >> b;
        cout << (n / 3) * min(3 * a, b) + min((n % 3) * a, b) << tata;
    }
    return 0;
}