#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, c = 0;
        scanf("%d", &n);
        char s[n];
        for (int i = 0; i < n; i++)
        {
            scanf(" %c", &s[i]);
            if (s[i] == 'U')
            {
                c++;
            }
        }
        if (c % 2 == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}