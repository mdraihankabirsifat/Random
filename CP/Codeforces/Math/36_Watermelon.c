// https://codeforces.com/problemset/problem/4/A
/*
Problem: Watermelon

Determine whether a watermelon of weight w can be split into two
positive parts that both have even weight.
*/

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    if (t <= 3)
    {
        printf("NO");
    }
    else if (t % 2 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
