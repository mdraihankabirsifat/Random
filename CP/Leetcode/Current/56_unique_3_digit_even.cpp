#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int totalNumbers(vector<int> &v)
    {
        int n = v.size(), ans = 0;
        vector<int> freq(1000);
        for (int i = 0; i < n; i++)
        {
            freq[v[i]]++;
        }
        for (int i = 100; i < 1000; i = i + 2)
        {
            int a = i / 100, b = (i / 10) % 10, c = i % 10;
            vector<int> p(10);
            p[a]++;
            p[b]++;
            p[c]++;
            if (freq[a] >= p[a] && freq[b] >= p[b] && freq[c] >= p[c])
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {1, 2, 3, 4};
    string s = "";
    ll n;
    Solution sol;
    cout << sol.totalNumbers(v);
    return 0;
}