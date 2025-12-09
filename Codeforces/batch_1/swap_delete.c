#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int count = 0, count_1 = 0;
        char str[200000];
        int num[200000];
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            num[i] = str[i] - '0';
            if (num[i] == 0)
            {
                count++;
            }
            if (num[i] == 1)
            {
                count_1++;
            }
        }
        if (count == 0)
        {
            printf("%d\n", count_1);
            goto here;
        }
        if (count_1 == 0)
        {
            printf("%d\n", count);
            goto here;
        }
        for (int i = 0; i < len; i++)
        {
            if (num[i] == 0)
            {
                count_1--;
                if (count_1 == 0)
                {
                    for (int j = i + 1; j < len; j++)
                    {
                        if (num[j] == 1)
                        {
                            count--;
                        }
                        if (num[j] == 0)
                        {
                            printf("%d\n", count);
                            goto here;
                        }
                        if (count == 0)
                        {
                            printf("0\n");
                            goto here;
                        }
                    }
                }
            }
            if (num[i] == 1)
            {
                count--;
                if (count == 0)
                {
                    for (int j = i + 1; j < len; j++)
                    {
                        if (num[j] == 0)
                        {
                            count_1--;
                        }
                        if (num[j] == 1)
                        {
                            printf("%d\n", count_1);
                            goto here;
                        }
                        if (count_1 == 0)
                        {
                            printf("0\n");
                            goto here;
                        }
                    }
                }
            }
        }
    here:;
    }
    return 0;
}