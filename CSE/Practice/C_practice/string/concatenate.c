#include <stdio.h>
#include <string.h>
int main()
{
    char a[11] = "bangla";
    char b[5] = "desh";
    int i = 0, j = 0;
    while (a[i])
        ++i;
    while (b[j])
    {
        a[i] = b[j];
        ++i, ++j;
    }
    a[i] = b[j]; // to copy '\0'
    fputs(a, stdout);
    printf("\n");

    char c[11] = "bangla";
    // b is joined after c and stores in c
    strcat(c, b);
    fputs(c, stdout);
    printf("\n");
    // a has "bangladesh"
    // c at its end has 3 chars of c
    strncat(c, b, 3);
    fputs(c, stdout);
    printf("\n");
    // c has "banglades"
    return 0;
}