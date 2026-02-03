#include <stdio.h>
int p(int arr[])
{
    int temp, i, count = 0;
    temp = arr[i];
    while (temp != 0)
    {
        count++;
        temp = (temp / 10);
    }
    int j;
    for (j = 1; j <= count; j = j++)
    {
        j = j * 10;
    }
    return j;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arr[i]);

        if (arr[i] > 0 && arr[i] < 9)
        {
            printf("%d\n%d", 1, arr[i]);
        }

        else if (arr[i] > 9 && (arr[i] % p(arr[i]))== 0)
        {
            printf("%d\n%d", 1, arr[i]);
        }
    }

    return 0;
}
//codeforces.com/problemset/problem/1352/A