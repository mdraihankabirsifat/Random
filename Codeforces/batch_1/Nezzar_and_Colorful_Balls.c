#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        int arr_1[105] = {0};
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            arr_1[arr[i]]++;
        }
        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            if (max < arr_1[i])
            {
                max = arr_1[i];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}