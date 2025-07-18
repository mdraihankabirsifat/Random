#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int l = 0; l < t; l++)
    {
        int n, k, s = 0;
        scanf("%d %d", &n, &k);
        if (k == 1)
        {
            printf("%d\n", n);
        }
        else
        {
            while (n != 0)
            {
                s = s + (n % k);
                n = n / k;
            }
            printf("%d\n", s);
        }
    }
    return 0;
}