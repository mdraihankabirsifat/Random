// https://codeforces.com/problemset/problem/2162/A
/*
Problem: Beautiful Average

Repeatedly replace two chosen values by their average under the given process.
Determine the maximum final value that can be achieved.
*/

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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << *max_element(v.begin(), v.end()) << "\n";
    }
    return 0;
}
