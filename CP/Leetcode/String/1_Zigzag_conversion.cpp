/*
Problem: Zigzag Conversion

Write a string in a zigzag across the requested number of rows, then
return the characters read row by row.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = numRows, m = s.size(), k = 0;
        vector<vector<char>> v(n, vector<char>(m));
        for (int j = 0; j < m; j++)
        {
            if (n == 1)
            {
                return s;
            }
            else if (j % (n - 1) == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    v[i][j] = s[k];
                    k++;
                    if (k > m)
                    {
                        m = j + 1;
                        goto end;
                    }
                }
            }
            else
            {
                v[n - (j % (n - 1)) - 1][j] = s[k];
                k++;
                if (k > m)
                {
                    m = j + 1;
                    goto end;
                }
            }
        }
    end:;
        k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j])
                {
                    s[k] = v[i][j];
                    k++;
                }
            }
        }
        return s;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll n;
    cin >> n;
    cin >> s;
    Solution sol;
    cout << sol.convert(s, n);
    return 0;
}
