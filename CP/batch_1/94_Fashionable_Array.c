#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        int arr_1[50] = {0};
        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = n-1; j > i; j--)
            {
                if ((arr[i] + arr[j]) % 2 != 0)
                {
                    c++;
                }
                else if ((arr[i] + arr[j]) % 2 == 0)
                {
                    arr_1[i] = i + c;
                    break;
                }
                if (c == 0)
                {
                    printf("0\n");
                    goto End;
                }
            }
        }
        int c=0, h = 0;
        while (arr_1[h+1] != 0)
        {
            if (arr_1[h] > arr_1[h+1])
            {
                int c = arr_1[h+1];
            }
            h++;
        }
        printf("%d\n", c);
    End:;
    }
    return 0;
}
//not yet