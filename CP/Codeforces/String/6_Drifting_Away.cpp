// https://codeforces.com/problemset/problem/2169/B
/*
Problem: Drifting Away

Analyze a line of directional cells and hazards to find how long drifting lasts,
or report -1 when the movement can continue indefinitely.
*/

#include <bits/stdc++.h>
#define ll long long
#define tata '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool k = true;
        int n = s.size(), l = 0, r = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && s[i] == '*' && (s[i - 1] == '*' || s[i - 1] == '>'))
                k = false;
            if (i < (n - 1) && s[i] == '*' && (s[i + 1] == '*' || s[i + 1] == '<'))
                k = false;
            if (i > 0 && s[i] == '<' && s[i - 1] == '>')
                k = false;
            if (i < (n - 1) && s[i] == '>' && s[i + 1] == '<')
                k = false;
            if (s[i] == '>')
                r++;
            if (s[i] == '<')
                l++;
            if (s[i] == '*')
                d++;
        }
        if (k)
        {
            int c = 0;
            c = max(l + d, r + d);
            cout << c << tata;
        }
        else
            cout << -1 << tata;
    }
    return 0;
}
