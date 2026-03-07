#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    int M[n + 1][W + 1];
    for (int w = 0; w <= W; w++)
    {
        M[0][w] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (wt[i - 1] > w)
            {
                M[i][w] = M[i - 1][w];
            }
            else
            {
                M[i][w] = max(M[i - 1][w], val[i - 1] + M[i - 1][w - wt[i - 1]]);
            }
        }
    }
    return M[n][W];
}

int main()
{
    int val[] = {1, 6, 18, 22, 28};
    int wt[] = {1, 2, 5, 6, 7};
    int W = 11;
    int n = 5;
    cout << knapsack(W, wt, val, n);
    return 0;
}