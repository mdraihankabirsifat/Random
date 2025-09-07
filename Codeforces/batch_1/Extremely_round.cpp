#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[999999];
    for (int i = 1; i <= 999999; i++)
    {
        int c = 0, y = i;
        while (y != 0)
        {
            if (y % 10 != 0)
            {
                c++;
            }
            y = y / 10;
        }
        if (c == 1)
        {
            arr[i] = arr[i - 1] + 1;
        }
        else
        {
            arr[i] = arr[i - 1];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}