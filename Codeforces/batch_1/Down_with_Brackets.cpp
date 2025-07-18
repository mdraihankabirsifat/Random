#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c = 0, f = 0;
        string s;
        cin >> s;
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == '(')
            {
                c++;
            }
            else
            {
                c--;
            }
            if (c < 0)
            {
                cout << "YES\n";
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            if (c == 0)
            {
                cout << "No\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
    return 0;
}