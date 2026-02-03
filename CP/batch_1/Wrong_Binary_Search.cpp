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
        int n;
        bool f = false;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if ((i == 0 && n > 1 && s[i + 1] == '1') ||
                    (i == n - 1 && n > 1 && s[i - 1] == '1') ||
                    (i > 0 && i < n - 1 && s[i - 1] == '1' && s[i + 1] == '1'))
                {
                    f = true;
                    break;
                }
            }
        }

        if (f)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            vector<int> z;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    z.push_back(i + 1);
                }
                else if (s[i] == '1')
                {
                    for (int j = z.size() - 1; j >= 0; j--)
                    {
                        cout << z[j] << " ";
                    }
                    z.clear();
                    cout << i + 1 << " ";
                }
            }
            for (int j = z.size() - 1; j >= 0; j--)
            {
                cout << z[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}