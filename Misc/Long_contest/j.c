#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    if (n == 1)
        printf("1\n");
    else if (n == 2)
        printf("2 1\n");
    else if (n == 3)
        printf("2 1 3\n");
    else
    {
        if (n % 2 == 0)
        {
            for (i = 1; 2 * i <= n; i++)
            {
                printf("%d ", 2 * i);
            }
            for (i = 3; i < n; i = i + 4)
            {
                printf("%d ", i);
            }
            int t = i - 4;
            if (t == n - 1)
            {
                for (i = 5; i < n; i = i + 4)
                {
                    printf("%d ", i);
                }
                printf("1");
            }
            else
            {
                for (i = 1; i < n; i = i + 4)
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
        else
        {
            for (i = 1; 2 * i <= n; i++)
            {
                printf("%d ", 2 * i);
            }
            for (i = 1; i <= n; i = i + 4)
            {
                printf("%d ", i);
            }
            int temp = i - 4;
            if (temp == n)
            {
                for (i = 5; i < n; i = i + 4)
                {
                    printf("%d ", i);
                }
                printf("3");
            }
            else
            {
                for (i = 3; i <= n; i = i + 4)
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}