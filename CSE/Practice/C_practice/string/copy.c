#include <stdio.h>
#include <string.h>
int main()
{
    char s[10] = "Supernova", t[10];
    int i = 0;
    while (s[i] != '\0')
    {
        t[i] = s[i];
        i++;
    }
    t[i] = s[i]; // copy '\0'
    fputs(t, stdout);
    printf("\n");

    strcpy(t, s); // copy from s to t
    fputs(t, stdout);
    printf("\n");
    strncpy(t, s, 5); // copy 5 chars
    t[5] = '\0';      // ensure null termination
    fputs(t, stdout);
    printf("\n");
    return 0;
}