#include <stdio.h>
int main()
{
    int a, b, c, t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (((a + b) == c) || ((a + c) == b) || ((b + c) == a))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
//codeforces.com/contest/1742/problem/