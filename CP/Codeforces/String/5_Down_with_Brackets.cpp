// https://codeforces.com/problemset/problem/2110/B
/*
Problem: Down with Brackets

Given a regular bracket sequence, determine whether removing one opening
and one closing bracket can make the remaining sequence irregular.
*/

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
