#include <stdio.h>
int main()
{
    int a, b, t, sum;
    char c;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %c %d", &a, &c, &b);
        sum = a + b;
        printf("%d\n", sum);
    }
    return 0;
}
//https://codeforces.com/problemset/problem/1772/A