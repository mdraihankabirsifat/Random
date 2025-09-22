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
        int n, c = 0;
        cin >> n;
        vector<int> v(n), freq(n+1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            freq[v[i]]++;
        }
        for (int i = 1; i <= 100; i++)
        {
            int g = c;
            c = 0;
            for (int j = 1; j < freq.size(); j++)
            {
                if (freq[j] >= i)
                {
                    c++;
                }
            }
            int m = c * i;
            c = max(m, g);
        }
        cout << c << "\n";
    }
    return 0;
}