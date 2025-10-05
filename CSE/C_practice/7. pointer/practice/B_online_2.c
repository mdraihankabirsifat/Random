#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int *merge_unique(const int *a, size_t n, const int *b, size_t m, size_t *out_len)
{
    size_t max_size = n + m;
    int *result = (int *)malloc(max_size * sizeof(int));
    size_t i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (*(a + i) < *(b + j))
        {
            *(result + k) = *(a + i);
            i++;
            k++;
        }
        else if (*(a + i) > *(b + j))
        {
            *(result + k) = *(b + j);
            j++;
            k++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < n)
    {
        *(result + k) = *(a + i);
        i++;
        k++;
    }

    while (j < m)
    {
        *(result + k) = *(b + j);
        j++;
        k++;
    }

    if (k == 0)
    {
        free(result);
        *out_len = 0;
        return NULL;
    }

    *out_len = k;
    return result;
}

int main()
{
    size_t n, m;
    scanf("%zu", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    scanf("%zu", &m);
    int *b = (int *)malloc(m * sizeof(int));
    for (size_t i = 0; i < m; i++)
    {
        scanf("%d", b + i);
    }

    size_t out_len;
    int *result = merge_unique(a, n, b, m, &out_len);

    printf("%zu\n", out_len);
    for (size_t i = 0; i < out_len; i++)
    {
        printf("%d ", *(result + i));
    }
    printf("\n");

    free(a);
    free(b);
    if (result)
    {
        free(result);
    }

    return 0;
}