// https://codeforces.com/problemset/problem/1703/B
/*
Problem: ICPC Balloons

Award one balloon for each solved problem and an extra balloon for its
first solution; compute the total balloons used.
*/

#include <stdio.h>
int main()
{
    int t, n, s;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int sum = 0;
        scanf("%d", &n);
        char arr[n];
        scanf("%s", &arr);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                s = 2;
            }
            else
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (arr[i] == arr[j])
                    {
                        s = 1;
                        break;
                    }
                    else
                    {
                        s = 2;
                    }
                }
            }
            sum = sum + s;
        }
        printf("%d\n", sum);
    }
    return 0;
}
