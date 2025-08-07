#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, c;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        c.push_back(s[i]);
    }
    if (s == c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}