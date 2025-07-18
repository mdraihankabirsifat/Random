#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int f = 0;
        string s;
        cin >> s;
        stack<char> st;
        for (auto x : s)
        {
            if (x == '(')
            {
                st.push(x);
            }
            else
            {
                if (st.empty())
                {
                    cout << "NO\n";
                    f = 1;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (f == 0)
        {
            if (st.empty())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}