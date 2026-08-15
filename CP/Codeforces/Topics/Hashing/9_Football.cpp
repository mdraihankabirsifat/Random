// https://codeforces.com/problemset/problem/43/A
/*
Problem: Football

Given the scorer of each football goal, output the team that scored
more goals.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, c = 0;
    cin >> n;
    vector<string> v(n);
    string a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[0] != v[i])
        {
            b = v[i];
        }
    }
    a = v[0];
    for (int i = 0; i < n; i++)
    {
        if (v[i] == a)
        {
            c++;
        }
    }
    string ans = c > (n - c) ? a : b;
    cout << ans << tata;
    return 0;
}