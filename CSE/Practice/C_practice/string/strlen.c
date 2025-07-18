#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "bangladesh";
    int length = strlen(str);
    printf("The length of the string '%s' is: %d\n", str, length);
    char *p = str;
    while (*p)
    {
        p++; // while (*p++);
    }
    length = p - str;
    printf("The length of the string '%s' calculated manually is: %d\n", str, length);
    return 0;
}