// https://codeforces.com/problemset/problem/2102/A
/*
Problem: Dinner Time

Determine whether an array of length n and sum m can satisfy the required
length-p segment-sum condition q.
*/

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, p, q;
        scanf("%d %d %d %d", &n, &m, &p, &q);
        if (n % p == 0 && (n / p) * q != m)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
