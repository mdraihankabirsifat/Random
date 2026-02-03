#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, temp = 0, i = 0;
        cin >> n;
        string st;
        cin >> st;
        vector<int> v;
        for (char x : st)
        {
            v.push_back(x - '0');
            if (v[i] == 1 || v[i] == 4 || v[i] == 6 || v[i] == 8 || v[i] == 9)
            {
                cout << 1 << endl;
                cout << v[i] << endl;
                temp = 1;
                break;
            }
            i++;
        }
        if (temp != 1)
        {
            vector<int> p(100);
            for (int i = 2; i < 100; i++)
            {
                for (int j = 2; j * j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        p[i] = 1;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (p[v[i] * 10 + v[j]])
                    {
                        cout << 2 << endl;
                        cout << v[i] * 10 + v[j] << endl;
                        temp = 1;
                        break;
                    }
                }
                if (temp == 1)
                {
                    break;
                }
            }
        }
    }
    return 0;
}