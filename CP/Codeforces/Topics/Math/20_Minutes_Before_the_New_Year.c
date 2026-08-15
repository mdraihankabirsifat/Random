// https://codeforces.com/problemset/problem/1283/A
/*
Problem: Minutes Before the New Year

Compute how many minutes remain until midnight from the given hour and minute.
undefined
*/

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int h, m, rest;
        scanf("%d %d", &h, &m);
        rest = (23 - h) * 60 + (60 - m);
        printf("%d\n", rest);
    }
    return 0;
}
