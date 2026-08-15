// https://codeforces.com/problemset/problem/2114/A
/*
Problem: Square Year

Interpret a four-digit year as two two-digit numbers and determine whether
their sum squared equals the year.
*/

#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++)
    {
        int s = 0, x = 5;
        char n[x];
        scanf(" %s", n);
        for (int i = 0; i < 4; i++)
        {
            s = s * 10 + (n[i] - '0');
        }
        int p = sqrt(s);
        if (p * p == s)
        {
            printf("0 %d\n", p);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
