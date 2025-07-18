#include <stdio.h>
int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("1");
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] <= arr[i])
            {
                printf("1");
            }
            else
            {
                printf("1");
                int u=i, x=i;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] >= arr[u] && arr[j] <= arr[0] && arr[x]<=arr[j])
                    {
                        printf("1");
                        u=j;
                    }
                    else
                    {
                        printf("0");
                    }
                }
                goto here;
            }
        }
    here:;
        printf("\n");
    }

    return 0;
}