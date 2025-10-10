#include <stdio.h>
int strRlen(char s[])
{
    if (!*s)
    {
        return 0;
    }
    s++;
    return 1 + strRlen(s);
}
int main()
{
    char s[20] = "Sifat";
    printf("%d", strRlen(s));
}