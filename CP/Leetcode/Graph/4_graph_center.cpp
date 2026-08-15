/*
Problem: Find Center of Star Graph

Given the edges of a star graph, return the single center vertex that
is connected to every other vertex.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++)
        {
            v[edges[i][0]]++;
            v[edges[i][1]]++;
        }
        for (int i = 1; i < n + 2; i++)
        {
            if (v[i] == n)
            {
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v(3, vector<int>(2));
    v[0][0] = 1;
    v[0][1] = 2;
    v[1][0] = 2;
    v[1][1] = 3;
    v[2][0] = 4;
    v[2][1] = 2;
    Solution sol;
    cout << sol.findCenter(v);
    return 0;
}
