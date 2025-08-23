#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        string s1, s2, s3, end;
        deque<char> st;
        cin >> a >> s1 >> b >> s2 >> s3;
        for (int i = 0; i < b; i++)
        {
            if (s3[i] == 'V')
            {
                st.push_front(s2[i]);
            }
            else
            {
                end.push_back(s2[i]);
            }
        }
        for (int i = 0; i < st.size(); i++)
        {
            cout << st[i];
        }
        cout << s1 + end << endl;
    }
    return 0;
}