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
        ll n;
        cin >> n;
        string s1, s2, s3;
        cin >> s1 >> s2;
        s3 = s1;
        vector<ll> v1, v2;
        for (int i = 0; i < n - 1; i++)
        {
            if (s1[i] != s2[i])
            {
                s1[i] = (s1[i] == '0') ? '1' : '0';
                s1[i + 1] = (s1[i + 1] == '0') ? '1' : '0';
                v1.pb(i);
                v2.pb(i + 1);
            }
        }
        if (s1 == s2)
        {
            ll k = v1.size();
            cout << k << endl;
            for (int i = 0; i < k; i++)
            {
                cout << v1[i] + 1 << " " << v2[i] + 1 << endl;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                s3[i] = (s3[i] == '0') ? '1' : '0';
            }
            if (s3 == s2)
            {
                cout << 1 << endl;
                cout << 1 << " " << n << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}