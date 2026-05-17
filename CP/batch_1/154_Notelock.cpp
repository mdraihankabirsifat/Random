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
        int n, k, p = 0, c = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                p = 0;
                for (int j = i - k + 1; j < i; j++)
                {
                    if (s[j] == '1')
                    {
                        p = 1;
                        break;
                    }
                }
                if (p == 0)
                {
                    c++;
                }
            }
        }
        cout << c << "\n";
    }
    return 0;
}