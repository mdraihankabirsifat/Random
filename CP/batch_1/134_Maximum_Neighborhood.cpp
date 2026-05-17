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
        ll n, m = 0, c = 0;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v[i][j] = ++c;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ll sum = v[i][j];
                if (i > 0)
                    sum += v[i - 1][j];
                if (i < n - 1)
                    sum += v[i + 1][j];
                if (j > 0)
                    sum += v[i][j - 1];
                if (j < n - 1)
                    sum += v[i][j + 1];
                m = max(m, sum);
            }
        }
        cout << m << endl;
    }
    return 0;
}