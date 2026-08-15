// https://codeforces.com/problemset/problem/2227/B
/*
Problem: Party Monster

Determine whether the given parenthesis string has equal numbers of
opening and closing parentheses.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int o = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                o++;
        }
        if (o == n - o)
            yes;
        else
            no;
    }
    return 0;
}
