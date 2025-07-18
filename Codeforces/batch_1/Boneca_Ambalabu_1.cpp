#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> ones(31);
        for (int i = 0; i < n; i++)
        {
            for (int b = 0; b < 31; b++)
            {
                if (v[i] & (1LL << b))
                {
                    ones[b]++;
                }
            }
        }
        long long best = 0;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int b = 0; b <= 30; b++)
            {
                long long bit_val = (1LL << b);
                if (v[i] & bit_val)
                {
                    sum += (n - ones[b]) * bit_val;
                }
                else
                {
                    sum += ones[b] * bit_val;
                }
            }
            best = max(best, sum);
        }

        cout << best << endl;
    }
    return 0;
}