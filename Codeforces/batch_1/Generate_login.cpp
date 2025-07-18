#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int p, t;
    vector<char> s;
    while (cin.get(c) && c != '\n')
    {
        s.push_back(c);
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == ' ')
        {
            p = s[i + 1];
            t = i;
            break;
        }
    }
    cout << s[0];
    for (int i = 1; i < t; i++)
    {
        if (s[i] < p)
        {
            cout << s[i];
        }
        else
        {
            break;
        }
    }
    cout << s[t + 1];
    return 0;
}