// https://codeforces.com/problemset/problem/486/A
/*
Problem: Calculating Function

Evaluate the alternating signed sum from 1 through n, where odd terms
are subtracted and even terms are added.
*/

#include <stdio.h>
#include <math.h>
int main()
{
    long long i = 0, n, sum = 0;
    scanf("%lld", &n);
    for (i = 0; i <= n; i++)
    {
        sum = sum + i * (pow(-1, i));
    }
    printf("%lld", sum);
    return 0;
}
