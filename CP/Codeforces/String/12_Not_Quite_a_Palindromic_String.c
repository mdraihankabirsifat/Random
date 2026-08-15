// https://codeforces.com/problemset/problem/2114/B
/*
Problem: Not Quite a Palindromic String

Rearrange a binary string so exactly k mirrored position pairs contain
equal characters, or report that this is impossible.
*/

#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        char string[n + 1];
        scanf(" %s", string);
        for (int i = 0; i < n; i++)
        {
            string[i] = string[i] - '0';
            
        }
    }
    return 0;
}
