#include <stdio.h>
int main()
{
    int t, n, count;
    scanf("%d", &t);
    int test = 0;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    if (count == 2)
                    {
                        test = 1;
                        printf("%d", arr[i]);
                        break;
                    }
                }
            }
        }
        if (test == 0)
        {
            printf("-1");
        }
        if (test == 1)
        {
            break;
        }
        printf("\n");
    }
    return 0;
}
//https://codeforces.com/problemset/problem/1669/B