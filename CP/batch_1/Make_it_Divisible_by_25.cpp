#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long num;
        cin >> num;
        vector<long long> v;
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((s[i] == '0' && s[j] == '0') || (s[i] == '2' && s[j] == '5') || (s[i] == '5' && s[j] == '0') || (s[i] == '7' && s[j] == '5'))
                {
                    v.push_back(n - (i + 2));
                }
            }
        }
        sort(v.begin(), v.end());
        cout << v[0] << "\n";
    }
    return 0;
}