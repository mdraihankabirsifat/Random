// https://codeforces.com/problemset/problem/2020/A
/*
Problem: Find Minimum Operations

Using powers of k any number of times, represent n with the minimum
number of summands.
*/

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for (int l = 0; l < t; l++)
    {
        int n, k, s = 0;
        scanf("%d %d", &n, &k);
        if (k == 1)
        {
            printf("%d\n", n);
        }
        else
        {
            while (n != 0)
            {
                s = s + (n % k);
                n = n / k;
            }
            printf("%d\n", s);
        }
    }
    return 0;
}
