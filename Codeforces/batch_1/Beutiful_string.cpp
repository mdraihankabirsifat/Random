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
        string s;
        int n, c = 0;
        cin >> n;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                c++;
                v.push_back(i + 1);
            }
        }
        cout << c << "\n";
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}