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
        string s1, s2;
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}