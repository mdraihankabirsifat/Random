#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, q, a, t, x, y;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &n, &m, &q);
        scanf("%d %d", &x, &y);
        scanf("%d", &a);
        if (x < a && y > a)
        {
            int f = (abs(y - x)) / 2;
            printf("%d\n", f);
        }
        else if (x > a && y > a)
        {
            printf("%d\n", x - 1);
        }
        else if (x < a && y < a)
        {
            printf("%d\n", n - y);
        }
    }
    return 0;
}
//I loose!