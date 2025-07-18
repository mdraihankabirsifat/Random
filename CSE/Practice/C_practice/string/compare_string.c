#include <stdio.h>
#include <string.h>
int main()
{
    char *a = "bangladesh";
    char *b = "bangla";
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i])
    {
        ++i;
    }
    if (a[i] < b[i])
    {
        printf("a < b");
    }
    else if (a[i] > b[i])
    {
        printf("a > b");
    }
    else
    {
        printf("a == b");
    }
    printf("\n");

    int c = strcmp(a, b);
    if (c < 0)
        printf("a < b");
    else if (c > 0)
        printf("a > b");
    else
        printf("a == b");
    //printf("\n%d\n", c);

    // compare first 6 characters
    c = strncmp(a, b, 6); // c is
    if (c < 0)
        printf("a < b");
    else if (c > 0)
        printf("a > b");
    else
        printf("a == b");
    //printf("\n%d\n", c);
    return 0;
}