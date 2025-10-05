#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("myfile.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR");
        return 0;
    }
    int a = 2;
    float f = 5.2;
    char c = 'p';
    fprintf(fp, "%d\n%f\n%c\n", a, f, c);
    fclose(fp);
    return 0;
}