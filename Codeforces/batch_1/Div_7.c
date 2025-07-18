#include <stdio.h>
int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        if (n % 7 == 0)
        {
            printf("%d\n", n);
        }
        else if (n < 10)
        {
            printf("7\n");
        }
        else
        {
            int g = n / 10;
            for (int i = g * 10 + 1; i < g * 10 + 10; i++)
            {
                if (i % 7 == 0)
                {
                    printf("%d\n", i);
                    goto End;
                }
            }
        }
    End:;
    }
    return 0;
}
//https://codeforces.com/problemset/problem/1633/A