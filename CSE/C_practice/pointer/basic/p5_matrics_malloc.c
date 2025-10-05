#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char **p = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        *(p + i) = (char *)malloc(m * sizeof(char));
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", *(p + i) + j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%c ", *(*(p + i) + j));
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++)
    {
        free(*(p+i));
    }
    free(p);
    return 0;
}