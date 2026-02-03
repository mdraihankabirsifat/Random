#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    if (t <= 3)
    {
        printf("NO");
    }
    else if (t % 2 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}