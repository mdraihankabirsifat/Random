#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, f = 0, c = 0;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
            goto end;
        }
        while (a.size() < m)
        {
            a = a + a;
            c++;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a.substr(i, m) == b)
            {
                cout << c << endl;
                goto end;
            }
        }
        a = a + a;
        c++;
        for (int i = 0; i < a.size(); i++)
        {
            if (a.substr(i, m) == b)
            {
                cout << c << endl;
                goto end;
            }
        }
        cout << -1 << endl;
    end:;
    }
    return 0;
}