#include <stdio.h>
int GCD(int a, int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int LCM(int p, int q)
{
    return p*q/GCD(p,q);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (n == 1 || n == 2)
        {
            printf("Yes\n");
        }
        else
        {
            for (int i = 0; i < n - 2; i++)
            {
                if (arr[i + 1] != GCD(LCM(arr[i], arr[i + 1]), LCM(arr[i + 1], arr[i + 2])))
                {
                    printf("No\n");
                    goto here;
                }
            }
            printf("Yes\n");
        }
    here:;
    }
    return 0;
}