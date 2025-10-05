#include <stdio.h>
int calculateHindex(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < i)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int a[100], n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int c = calculateHindex(arr, n);
    printf("%d", c);
    return 0;
}