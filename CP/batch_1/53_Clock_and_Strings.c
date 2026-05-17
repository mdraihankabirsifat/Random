#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int arr[13] = {0};
        arr[a] = 1;
        arr[b] = 1;
        arr[c] = 2;
        arr[d] = 2;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < 13; i++)
        {
            if (arr[i] == 1)
            {
                c2 = 0;
                c1++;
            }
            else if (arr[i] == 2)
            {
                c1 = 0;
                c2++;
            }
            if (c1 == 2 || c2 == 2)
            {
                printf("No\n");
                goto End;
            }
        }
        printf("Yes\n");
    End:;
    }
    return 0;
}