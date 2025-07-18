#include <stdio.h>
#include <stdlib.h>
int main()
{
    char str[10] = "14235";
    int num = 0, i = 0;
    while (str[i] != '\0') // or (str[i])
    {
        num = num * 10 + (str[i] - '0');
        i = i + 1;
    }
    printf("%i\n", num);

    num = atoi(str);
    printf("%i\n", num);
    long l = atol(str);
    printf("%ld\n", l);

    char p[5] = "12.34";
    float f = atof(p);
    printf("%f\n", f);
    double d = atof("12.34");
    printf("%.2f\n", d); 
    return 0;
}