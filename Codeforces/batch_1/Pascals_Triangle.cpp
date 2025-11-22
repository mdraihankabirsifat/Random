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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> prev;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> current(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                current[j] = prev[j - 1] + prev[j];
            }
            result.push_back(current);
            prev = current;
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Solution sol;
    auto triangle = sol.generate(n);
    for (auto &row : triangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}