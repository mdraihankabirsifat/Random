#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        int last = -1, s = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] - last > 1)
            {
                s++;
                last = arr[i];
            }
        }
        cout << s << "\n";
    }
    return 0;
}