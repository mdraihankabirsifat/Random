#include <bits/stdc++.h>
using namespace std;
vector<int> repeat(string x)
{
    vector<int> res;
    int c = 1;
    for (int i = 1; i <= x.size(); i++)
    {
        if (i < x.size() && x[i] == x[i - 1])
        {
            c++;
        }
        else
        {
            if (x[i - 1] == 'L')
            {
                res.push_back(c);
            }
            else
            {
                res.push_back(-c);
            }
            c = 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s;
        cin >> p;
        vector<int> s1, p1;
        s1 = repeat(s);
        p1 = repeat(p);
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1.size() != p1.size())
            {
                cout << "NO\n";
                break;
            }
            else if (s1[i] > 0 && p1[i] < 0 || s1[i] < 0 && p1[i] > 0)
            {
                cout << "NO\n";
                break;
            }
            else if (abs(s1[i]) <= abs(p1[i]) && abs(p1[i]) <= abs(2 * s1[i]))
            {
                if (i == s1.size() - 1)
                {
                    cout << "YES\n";
                    break;
                }
            }
            else
            {
                cout << "NO\n";
                break;
            }
        }
    }
    return 0;
}