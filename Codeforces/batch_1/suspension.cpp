#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define msort(x) sort(x.begin(), x.end())
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, y, r;
        cin >> n;
        cin >> y >> r;
        ll p = r + y / 2;
        if (p > n)
        {
            cout << n << endl;
        }
        else
        {
            cout << p << endl;
        }
    }
    return 0;
}