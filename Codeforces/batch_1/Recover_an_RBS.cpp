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
        int c = 0, q = 0, f = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || i == 0 || (s[i] == '?' && c == 0))
            {
                c++;
            }
            else if (s[i] == ')' || i == s.size() - 1)
            {
                c--;
            }
            else
            {
                q++;
            }
        }
        if (q == abs(c))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}