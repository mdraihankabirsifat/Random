#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, flag = 0;
        cin >> n;
        vector<int> v(n), p(n), k;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        p = v;
        sort(p.begin(), p.end());
        if (v == p)
        {
            cout << "No" << endl;
        }
        else if (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == p[i])
                {
                    flag = 1;
                }
                else
                {
                    k.push_back(v[i]);
                }
            }
            if (flag == 1)
            {
                cout << "Yes" << endl;
                cout << k.size() << endl;
                for (int i = 0; i < k.size(); i++)
                {
                    cout << k[i] << " ";
                }
                cout << endl;
            }
            else
            {
                goto here;
            }
        }
        else
        {
        here:;
            cout << "Yes" << endl;
            cout << v.size() << endl;
            for (int i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}