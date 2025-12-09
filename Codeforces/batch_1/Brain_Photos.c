#include <stdio.h>
#include <string.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }
    int color = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'C' || arr[i][j] == 'M' || arr[i][j] == 'Y')
            {
                printf("#Color");
                goto End;
            }
        }
    }
    printf("#Black&White\n");
End:;
    return 0;
}
// https://codeforces.com/problemset/problem/707/A