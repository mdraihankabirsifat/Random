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