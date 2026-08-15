// https://codeforces.com/problemset/problem/200/B
/*
Problem: Drinks

Compute the average percentage of orange juice in the given drinks.
undefined
*/

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    float ans;
    ans= ((sum/(n*100))*100);
    printf("%f", ans);
    return 0;
}
//codeforces.com/problemset/problem/200/B
