#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("myfile.txt", "r");
    if (fp == NULL)
    {
        printf("ERROR");
        fclose(fp);
    }
    int a;
    float f;
    char c;
    fscanf(fp, "%d %f %c", &a, &f, &c);
    printf("%d %f %c", a, f, c);
    fclose(fp);
    return 0;
}