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
        ll n, c = 0;
        cin >> n;
        vector<int> v(n), p(101);
        loop(i, n)
        {
            cin >> v[i];
            p[v[i]]++;
        }
        for (int i = 0; i < 101; i++)
        {
            if (p[i] && p[i] != i)
            {
                if (p[i] > i)
                {
                    c += p[i] - i;
                }
                else
                {
                    c += p[i];
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}