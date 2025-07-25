#include <stdio.h>
#include <string.h>
int main()
{
    char s[] = "abcdbce";
    char p[] = "bc";
    for (int i = 0; i <= strlen(s) - strlen(p); i++)
    {
        if (strncmp(s + i, p, strlen(p)) == 0)
        {
            printf("found at %d\n", i);
        }
    }
    return 0;
}