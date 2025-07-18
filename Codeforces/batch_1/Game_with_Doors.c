#include <stdio.h>
int main()
{
    int t, l, r, L, R;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &l, &r);
        scanf("%d %d", &L, &R);
        if (l > L && r > R && l < R)
        {
            printf("%d\n", R - l + 2);
        }
        else if (l < L && r < R && r > L)
        {
            printf("%d\n", r - L + 2);
        }
        else if (l < L && r > R)
        {
            printf("%d\n", R - L + 2);
        }
        else if (l > L && r < R)
        {
            printf("%d\n", r - l + 2);
        }
        else if (l > L && r == R)
        {
            printf("%d\n", r - l + 1);
        }
        else if (l < L && r == R)
        {
            printf("%d\n", r - L + 1);
        }
        else if (l == L && r < R)
        {
            printf("%d\n", r - l + 1);
        }
        else if (l == L && r > R)
        {
            printf("%d\n", R - l + 1);
        }
        else if (l == L && r == R)
        {
            printf("%d\n", r - l);
        }
        else if (l > L && r > R && R < l)
        {
            printf("1\n");
        }
        else if (l < L && r < R && r < L)
        {
            printf("1\n");
        }
        else if (l > L && r > R && R <= l)
        {
            printf("2\n");
        }
        else if (l < L && r < R && r <= L)
        {
            printf("2\n");
        }
    }
    return 0;
}