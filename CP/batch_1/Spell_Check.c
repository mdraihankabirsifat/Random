#include <stdio.h>
int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        char s[10];
        scanf("%s", s);
        if (n != 5)
        {
            printf("NO\n");
        }
        if (n == 5)
        {
            for (int i = 0; i < 5; i++)
            {
                if (s[i] == 'T' || s[i] == 'i' || s[i] == 'm' || s[i] == 'u' || s[i] == 'r')
                {
                    continue;
                }
                else
                {
                    printf("NO\n");
                    goto End;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = i + 1; j < 5; j++)
                {
                    if (s[i] == s[j])
                    {
                        printf("NO\n");
                        goto End;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            printf("YES\n");
        End:;
        }
    }

    return 0;
}