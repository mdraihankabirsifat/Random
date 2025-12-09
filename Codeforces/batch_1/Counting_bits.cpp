#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define msort(x) sort(x.begin(), x.end())
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v(n + 1);
        int c = 0;
        for (int i = 0; i <= n; i++)
        {
            unsigned int m = 1;
            c = 0;
            for (int j = 0; j < 31; j++)
            {
                if (i & m)
                {
                    v[i] = ++c;
                }
                m <<= 1;
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    Solution sol;
    vector<int> p;
    p = sol.countBits(x);
    for (int i = 0; i <= x; i++)
    {
        cout << p[i] << ",";
    }
    cout << endl;
    return 0;
}