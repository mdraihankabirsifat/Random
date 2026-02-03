#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() == 1)
        {
            cout << -1 << endl;
        }
        else if (s.size() == 2)
        {
            if (s[0] == s[1])
            {
                cout << s << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else
        {
            int track = 0;
            for (int i = 0; i < s.size() - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    cout << s[i] << s[i + 1] << endl;
                    track = 1;
                    break;
                }
                else if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2] && i < s.size() - 2)
                {
                    cout << s[i] << s[i + 1] << s[i + 2] << endl;
                    track = 1;
                    break;
                }
            }
            if (track == 0)
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}