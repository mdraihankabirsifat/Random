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
        int n, c = 0, a = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
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
                a++;
                c = 0;
            }
        }
        cout << a << "\n";
    }
    return 0;
}