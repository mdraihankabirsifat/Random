#include <stdio.h>
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        int flag = 0;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (arr[0] == 1 && arr[1] == 1)
        {
            printf("Yes\n");
            flag = 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == 0 && arr[i + 1] == 0)
            {
                printf("Yes\n");
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("No\n");
        }
    }
    return 0;
}
//not completed yet