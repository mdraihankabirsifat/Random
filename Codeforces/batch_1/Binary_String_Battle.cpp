#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, c = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                c++;
            }
        }
        if (c == 0)
        {
            cout << "Alice" << endl;
        }
        else if (c == k || c < k)
        {
            cout << "Alice" << endl;
        }
        else
        {
            if (n / 2 < k)
            {
                cout << "Alice" << endl;
            }
            else
            {
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}