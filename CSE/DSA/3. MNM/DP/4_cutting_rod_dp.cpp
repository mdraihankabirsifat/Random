#include <iostream>
#include <climits>
using namespace std;

int bottomUpCutRod(int price[], int n)
{
    int r[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        // j=1
        int q = INT_MIN;
        // q=-1
        for (int i = 1; i <= j; i++)
        {
            q = max(q, price[i] + r[j - i]);
        }
        r[j] = q;
        // r[1]=1
        // r[2]=5
        // r[3]=8
        // r[4]=
    }
    // price[i] + r[j - i]
    // 3 2
    // 3 1 1

    // for r[i] + r[j - i]
    //  3 2
    //  1 1 1 2
    //  1 1 1 1 1
    //  3 2
    //  3 1 1
    //  2 1 1 1
    //  1 2 1 1
    //  2 1 2
    //  1 2 2
    return r[n];
}

int main()
{
    int price[] = {0, 3, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;
    cout << "Maximum Revenue = " << bottomUpCutRod(price, n);
    return 0;
}