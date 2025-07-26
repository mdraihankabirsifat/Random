#include <stdio.h>
int main()
{
    char str[100], revstr[100];
    gets(str);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] == '\0';
            break;
        }
        i++;
    }
    int len = i - 1;
    for (i = 0; i <= len / 2; i++)
    {
        revstr[i] = str[len - i];
        revstr[len - i] = str[i];
    }
    puts(revstr);
    return 0;
}