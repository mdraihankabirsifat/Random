#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = "- This, a sample-string.";
    char *p;
    p = strtok(s, " ,.-");
    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, " ,.-");
    }
    return 0;
}