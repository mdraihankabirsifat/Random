#include <stdio.h>
int main()
{
    FILE *fp = fopen("myfile.txt", "r+"); // Changed to "r+" for both read and write
    if (fp == NULL)
    {
        printf("Error opening file");
        return 1;
    }
    int num = 0, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        fscanf(fp, "%d", &num);
        sum = sum + num;
    }
    //fseek(fp, 0, SEEK_END);  // Move to end of file
    fprintf(fp, "\n%d", sum);
    fclose(fp);
}