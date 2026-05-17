#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, c = 1, x, y, z;
        scanf("%d", &n);
        int arr[n+2];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            if (i == n - 1)
            {
                arr[n] = 0;
                arr[n+1] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] + 1 < arr[i + 1])
            {
                c++;
            }
            else if (arr[i] + 1 == arr[i + 1] && arr[i + 1] + 1 == arr[i + 2])
            {
                c++;
                i = i + 2;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}