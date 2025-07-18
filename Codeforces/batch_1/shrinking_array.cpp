#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int i;
        for (i = 1; i < n; i++)
        {
            if (abs(arr[i] - arr[i - 1]) <= 1)
            {
                printf("%d\n", 0);
                break;
            }
        }
        if (i == n)
        {
            if (is_sorted(arr.begin(), arr.end()) || is_sorted(arr.begin(), arr.end(), greater<int>()))
            {
                printf("%d\n", -1);
            }
            else
            {
                printf("%d\n", 1);
            }
        }
    }
}