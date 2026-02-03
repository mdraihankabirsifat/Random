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