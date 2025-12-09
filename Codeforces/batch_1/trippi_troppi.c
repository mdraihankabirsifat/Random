#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        char charr[40];
        scanf(" %[^\n]", charr);
        printf("%c", charr[0]);
        for (int i = 1; i < 40; i++)
        {
            if (charr[i] == ' ' && charr[i + 1] != ' ')
            {
                printf("%c", charr[i + 1]);
            }
            if (charr[i]=='\0')
            break;
        }
        printf("\n");
    }
    return 0;
}