#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, sum = 0, c = 0;
        cin >> n;
        vector<long long> v(n), freq(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum = sum + v[i];
            freq[i] = sum;
        }
        for (int j = 1; j < n; j++)
        {
            for (int k = j; k <= j; k++)
            {
                if (freq[k] - v[k] == freq[k - 1])
                {
                    c++;
                    break;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}