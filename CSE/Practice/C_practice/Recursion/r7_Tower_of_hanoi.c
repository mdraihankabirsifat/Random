#include <stdio.h>
void TOH(int n, char s, char t, char b)
{
    if (n == 1)
    {
        printf("Move disc 1 from %c to %c\n", s, t);
    }
    else
    {
        // Step 1: Move n-1 discs from source to temporary
        TOH(n - 1, s, b, t);
        // Step 2: Move nth disc from source to target
        printf("Move disc %d from %c to %c\n", n, s, t);
        // Step 3: Move n-1 discs from temporary to target
        TOH(n - 1, b, t, s);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B'); // A = source, C = target, B = temporary
    return 0;
}