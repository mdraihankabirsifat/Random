#include <stdio.h>
int main()
{
    int x, y, t, n, k;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &x, &y, &n);
        k = ((n - y) / x) * x + y;
        printf("%d\n", k);
        // for (int i = n; i > 0; i--)
        // {
        //     if (i < x)
        //     {
        //         printf("0\n");
        //         break;
        //     }
        //     if ((i % x) == y)
        //     {
        //         printf("%d\n", i);
        //         break;
        //     }
        // }
    }

    return 0;
}