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
        ll n, x, y, c = 0;
        cin >> n >> x >> y;
        x = abs(x);
        y = abs(y);
        string s;
        cin >> s;
        loop(i, n)
        {
            if (s[i] == '4')
            {
                c++;
            }
        }
        if (x <= n && y <= n)
        {
            if (y <= 2 * n - c - x)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}