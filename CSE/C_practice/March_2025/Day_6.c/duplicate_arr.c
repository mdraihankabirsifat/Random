#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int dup = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                dup = 1;
                break;
            }
        }
    }
    if (dup)
    {
        printf("Yes");
    }
    else
    {
        printf("NO");
    }

    return 0;
}