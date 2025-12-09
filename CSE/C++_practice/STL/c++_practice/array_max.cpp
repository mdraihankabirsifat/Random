#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m1 = *max_element(arr, arr + n);
    cout << m1 << endl;
    cin >> m;
    int arr_1[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr_1[i][j];
        }
    }
    int m2 = arr_1[0][0];
    for (int i = 0; i < n; i++)
    {
        int r_m = *max_element(arr_1[i], arr_1[i] + m);
        m2 = max(m2, r_m);
    }
    cout << m2 << endl;
    return 0;
}