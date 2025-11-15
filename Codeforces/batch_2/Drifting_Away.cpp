#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int star = 0, l = 0, p = 0, c = 0, k = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                star++;
            }
            if (s[i] == '>' && p == 0)
            {
                p = 1;
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[j] == '<')
                    {
                        cout << -1 << "\n";
                        goto end;
                    }
                }
            }
        }
        if (star > 1)
        {
            cout << -1 << "\n";
            goto end;
        }
        if (star == s.size())
        {
            cout << 1 << "\n";
            goto end;
        }
        for (int i = 0; i < s.size(); i++)
        {
            l = c;
            c = 0;
            k = i;
            if (s[i] == '*')
            {
                c++;
                i++;
                k++;
            }
            while (s[i] == s[k] || s[k] == '*' && s[i] == '*')
            {
                c++;
                k++;
            }
            c = max(l, c);
        }
        cout << c << "\n";
    end:;
    }
    return 0;
}