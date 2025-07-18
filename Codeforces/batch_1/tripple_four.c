#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    if (N <= 2)
    {
        printf("Error");
    }
    else
    {
        int arr[N], temp = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < (N - 2); i++)
        {
            if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i + 2])
            {
                printf("Yes");
                temp = 1;
                break;
            }
        }
        if (temp != 1)
        {
            printf("No");
        }
    }
    return 0;
}