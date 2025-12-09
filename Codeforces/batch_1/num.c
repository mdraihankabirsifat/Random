#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int len, i, n, num[100];
    printf("Enter the number & the value of n: ");
    scanf("%s %d", str, &n);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        num[i] = str[i] - '0';
    }
    printf("%d", num[n-1]);
    return 0;
}