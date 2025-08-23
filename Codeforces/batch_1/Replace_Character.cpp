#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int c = 0, f = 0, g = 11;
        char max = s[0], min = s[0], m;
        for (int i = 0; i < n; i++)
        {
            c = 0;
            for (int j = 0; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    c++;
                }
            }
            if (f < c)
            {
                max = s[i];
                f = c;
            }
            if (g > c)
            {
                min = s[i];
                g = c;
            }
        }
        if (min == max)
        {
            for (int i = 0; i < n; i++)
            {
                c = 0;
                for (int j = 0; j < n; j++)
                {
                    if (s[i] == s[j])
                    {
                        c++;
                    }
                }
                if (c == g && s[i] != max)
                {
                    min = s[i];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == min)
            {
                s[i] = max;
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}