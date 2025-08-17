#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, c = 0, temp = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v('z' + 1);
        for (int i = 0; i < n; i++)
        {
            v[s[i]]++;
        }
        int odd = 0;
        for (int i = 'a'; i < 'z' + 1; i++)
        {
            if (v[i] % 2 != 0)
            {
                odd++;
            }
        }
        if (odd > k + 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}