#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        vector<int> c(3);
        for (int i = 0; i < stones.size(); i++)
        {
            c[stones[i] % 3]++;
        }
        if (c[0] % 2 == 0)
        {
            return c[1] > 0 && c[2] > 0;
        }
        return abs(c[1] - c[2]) > 2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {2,1};
    Solution sol;
    if (sol.stoneGameIX(v))
        yes;
    else
        no;
    return 0;
}