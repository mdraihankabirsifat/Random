#include <stdio.h>
int main()
{
    int n, a, b, c, d;
    scanf("%d", &n);
    a = n / 1000;
    b = (n % 1000) / 100;
    c = (n % 100) / 10;
    d = n % 10;
    int s = a + b*10 + c*100 + d*1000;
    printf("%d", s);
    return 0;
}