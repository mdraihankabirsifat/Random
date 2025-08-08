#include <stdio.h>
#include <stdlib.h>
int main()
{
    int **p;
    int m, n;
    scanf("%d %d", &m, &n);
    p = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        *(p + i) = malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (*(p + i) + j));
        }
    }
    int min = **p, max = **p;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(*(p + i) + j) > max)
                max = *(*(p + i) + j);
            if (*(*(p + i) + j) < min)
                min = *(*(p + i) + j);
        }
    }
    printf("%d %d\n", min, max);
    int idx1, idx2;
    scanf("%d %d", &idx1, &idx2);
    idx1--;
    idx2--;
    int *t;
    t = *(p + idx1);
    *(p + idx1) = *(p + idx2);
    *(p + idx2) = t;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    scanf("%d %d", &idx1, &idx2);
    idx1--;
    idx2--;
    for (int i = 0; i < m; i++)
    {
        int r;
        r = *(*(p + i) + idx1);
        *(*(p + i) + idx1) = *(*(p + i) + idx2);
        *(*(p + i) + idx2) = r;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        free(*(p + i));
    }
    free(p);
    return 0;
}
