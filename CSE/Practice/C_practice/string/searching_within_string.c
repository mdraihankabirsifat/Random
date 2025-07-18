#include <stdio.h>
#include <string.h>
int main()
{
    char *s = "12:130:45:1";
    char *p = strchr(s, ':');
    if (p)
        printf("first at %li\n", p - s); // find first occurrence
    char *q = strrchr(s, ':');
    if (q)
        printf("last at %li\n", q - s); // find last occurrence
    printf("all occurrences:\n");
    char *k = s;
    while (k = strchr(k, ':'))
        if (k) // p != NULL
        {
            printf("at %li\n", k - s);
            ++k;
        }
    return 0;
}