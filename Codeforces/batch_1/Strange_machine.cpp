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
        long long n, q, B1 = -1;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<long long> v1(n), v2(n);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'B')
            {
                B1 = i;
                break;
            }
        }
        if (B1 != -1)
        {
            long long Bl = B1, Ac = 0;
            for (long long k = 0; k < n; ++k)
            {
                long long i = (B1 - 1 - k + 2 * n) % n;
                if (s[i] == 'A')
                {
                    Ac++;
                }
                else
                {
                    Bl = i;
                    Ac = 0;
                }
                v1[i] = Bl;
                v2[i] = Ac;
            }
        }
        for (int k = 0; k < q; ++k)
        {
            long long v;
            cin >> v;
            if (B1 == -1)
            {
                cout << v << "\n";
                continue;
            }
            long long st = 0, idx = 0;
            while (v > 0)
            {
                long long nA = v2[idx], bin = v1[idx];
                v = v - nA;
                st = st + nA;
                if (v <= 0)
                {
                    st += v;
                    break;
                }
                v = v / 2;
                st++;
                idx = (bin + 1) % n;
            }
            cout << st << "\n";
        }
    }
    return 0;
}