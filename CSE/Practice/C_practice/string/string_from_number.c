#include <stdio.h>
int main()
{
    int num = 2367;
    char str[10];
    int i = 0;
    do
    {
        str[i] = num % 10 + '0';
        num = num / 10;
        i = i + 1;
    } while (num != 0);
    str[i] = '\0';
    i = i - 1;
    // string str is to be inverted
    int j = 0;
    while (j < i)
    {
        char c = str[j]; // swap str[i], str[j]
        str[j] = str[i];
        str[i] = c;
        ++j;
        --i;
    }
    printf("%s", str);
    printf("\n");
    
    int y = 523;
    char str[10];
    sprintf(str, "%d", y);
    printf("%s", str);
    return 0;
}