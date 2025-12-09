#include <stdio.h>
int main()
{
    int a, b, t, min, max, count;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        int count = 0;
        if(a%b==0)
        {
            printf("0\n");
        }
        else if (a > b)
        {
            count = ((((a / b) + 1)* b) - a);
            printf("%d\n", count);
        }
        else
        {
            count = (b-a);
            printf("%d\n", count);
        }
    }
    return 0;
}

//codeforces.com/problemset/problem/1328/A