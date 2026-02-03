#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, s, i;
        scanf("%d %d", &n, &s);
        int arr[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (arr[0] == s || arr[n - 1] == s)
        {
            printf("%d\n", arr[n - 1] - arr[0]);
        }
        else if (arr[0] > s && arr[n - 1] > s)
        {
            printf("%d\n", arr[n - 1] - s);
        }
        else if (arr[0] < s && arr[n - 1] < s)
        {
            printf("%d\n", s - arr[0]);
        }
        else
        {
            int t1 = 2 * (s - arr[0]) + arr[n - 1] - s;
            int t2 = s - arr[0] + 2 * (arr[n - 1] - s);
            if (t1 == t2)
            {
                printf("%d\n", t1);
            }
            else if (t1 < t2)
            {
                printf("%d\n", t1);
            }
            else
            {
                printf("%d\n", t2);
            }
        }
    }
    return 0;
}