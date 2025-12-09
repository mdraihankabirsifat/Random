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
        ll n, s = 0;
        cin >> n;
        vector<int> v;
        loop(i, n)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                v.pb(x);
                s += x;
            }
        }
        msort(v);
        int l = v.size();
        int p = l;
        n--;
        for (int i = 0; i < p; i++)
        {
            if (s - l >= n)
            {
                cout << p - i << endl;
                break;
            }
            s = s - v[i];
            l--;
            n--;
        }
    }
    return 0;
}