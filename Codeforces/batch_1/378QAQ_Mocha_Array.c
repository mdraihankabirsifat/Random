#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, temp = 1000000000, temp_1 = 1000000000, count = 0;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (temp > arr[i])
            {
                temp = arr[i];
            }
        }
        if (temp == 1)
        {
            printf("YES\n");
            goto End;
        }

        for (int i = 0; i < n; i++)
        {
            if (temp_1 > temp && temp_1 > arr[i])
            {
                if (arr[i] % temp == 0)
                {
                    goto here;
                }
                if (arr[i] == temp)
                {
                    goto here;
                }
                temp_1 = arr[i];
            here:;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % temp == 0 || arr[i] % temp_1 == 0)
            {
                count++;
            }
        }
        if (count == n)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    End:;
    }
    return 0;
}