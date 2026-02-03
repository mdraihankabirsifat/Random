#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        vector<long long> v(n);
        vector<int> v1(q);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < q; i++)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < q; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((v[j] % (1LL << v1[i])) == 0)
                {
                    v[j] = v[j] + (1LL << (v1[i] - 1));
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}