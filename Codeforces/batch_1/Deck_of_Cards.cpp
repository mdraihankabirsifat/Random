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
        int n, k, p0 = 0, p1 = 0, p2 = 0, j = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<string> v(n);
        for (int i = 0; i < k; i++)
        {
            if (s[i] == '0')
            {
                p0++;
            }
            else if (s[i] == '1')
            {
                p1++;
            }
            else
            {
                p2++;
            }
        }
        // cout << p0 << " " << p1 << " " << p2 << "\n";
        for (int i = 0; i < p0; i++)
        {
            v[i] = "-";
        }
        for (int i = 0; i < p1; i++)
        {
            v[n - i - 1] = "-";
        }
        float r = (n - p0 - p1) / 2.0;
        int y = p2;
        for (int i = p0; i < p0 + ceil(r); i++)
        {
            j++;
            if (p2 == 0)
            {
                v[i] = "+";
                v[n - p1 - j] = "+";
            }
            else if (p2 == n - p0 - p1)
            {
                v[i] = "-";
                v[n - p1 - j] = "-";
            }
            else if (i == p0 + ceil(r) - 1 && y == 1 && (n - p0 - p1) % 2 == 1)
            {
                v[i] = "-";
            }
            else
            {
                v[i] = "?";
                v[n - p1 - j] = "?";
                p2--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i];
        }
        cout << "\n";
    }
    return 0;
}