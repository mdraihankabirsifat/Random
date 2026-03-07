#include <iostream>
#include <algorithm>
using namespace std;
// time complexity O(mn)
// space complexity O(mn)
int sequenceAlignment(string x, string y, int gap, int mismatch)
{
    int m = x.size();
    int n = y.size();
    int M[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        M[i][0] = i * gap;
    }
    for (int j = 0; j <= n; j++)
    {
        M[0][j] = j * gap;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cost = (x[i - 1] == y[j - 1]) ? 0 : mismatch;
            M[i][j] = min({cost + M[i - 1][j - 1], gap + M[i - 1][j], gap + M[i][j - 1]});
        }
    }
    return M[m][n];
}

int main()
{
    string x = "occurance";
    string y = "occurrence";
    cout << sequenceAlignment(x, y, 2, 1);
    return 0;
}