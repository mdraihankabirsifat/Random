#include <stdio.h>
int main()
{
    int y, rem_1, rem_2, rem_3, rem_4;
    scanf("%d", &y);
    if (y >= 1000 && y <= 9000)
    {
    here:
        y++;
        rem_1 = y % 10;
        rem_2 = (y % 100) / 10;
        rem_3 = (y % 1000) / 100;
        rem_4 = y / 1000;
        if (rem_1 == rem_2 || rem_1 == rem_3 || rem_1 == rem_4 || rem_2 == rem_3 || rem_2 == rem_4 || rem_3 == rem_4)
            goto here;
        else
        {
            printf("%d", y);
        }
    }
    else
    {
        printf("Error");
    }
    return 0;
}