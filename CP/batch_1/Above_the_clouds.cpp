#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, flag = 0;
        string s;
        cin >> k;
        cin >> s;
        for (int i = k - 2; i > 0; i--)
        {
            if (s[k - 1] == s[i])
            {
                cout << "YES\n";
                goto here;
            }
        }
        for (int i = 0; i < k - 2; i++)
        {
            for (int j = i + 1; j < k - 1; j++)
            {
                if (s[i] == s[j])
                {
                    cout << "YES\n";
                    goto here;
                }
            }
        }
        cout << "NO\n";
    here:;
    }
    return 0;
}