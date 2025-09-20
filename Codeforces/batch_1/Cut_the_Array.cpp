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
        long long n, a, b, c;
        cin >> n;
        vector<long long> v(n), freq(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            freq[i + 1] = freq[i] + v[i];
        }
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                a = freq[i + 1] % 3;
                b = (freq[j + 1] - freq[i + 1]) % 3;
                c = (freq[n] - freq[j + 1]) % 3;
                if ((a == b && b == c) || (a != b && b != c && c != a))
                {
                    cout << i + 1 << " " << j + 1 << endl;
                    goto end;
                }
            }
        }
        cout << 0 << " " << 0 << endl;
    end:;
    }
    return 0;
}