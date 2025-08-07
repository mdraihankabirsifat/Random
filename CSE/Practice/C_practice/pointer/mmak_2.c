#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void take_input(int ***A, int m, int n)
{
    // int **A;
    *A = (int **)malloc(m * sizeof(int *));
    assert(*A != NULL);
    for (int i = 0; i < m; i++)
    {
        *(*A + i) = (int *)malloc(n * sizeof(int));
        assert(*(*A + i) != NULL);
    }
    // int **B=*A;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", *(*A + i) + j);
        }
    }
}
void free_matrix(int **A, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(*(A + i));
    }
    free(A);
}
void print_matrix(int **A, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(A + i) + j));
        }
    }
}

int main()
{
    int m, n;
    printf("\nGive the Dimension of the matrix: ");
    scanf("%d %d %d", &m, &n);
    int **A;
    take_input(&A, m, n);
    print_matrix(A, m, n);
    free_matrix(A, m);
}
