#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = "abcdbce";
    char pattern[] = "bc";
    char *t = s;
    while ((t = strstr(t, pattern)) != NULL)
    {
        printf("found at %d\n", t - s);
        t++; // move one character forward to search for overlapping occurrences
    }
    return 0;
}
