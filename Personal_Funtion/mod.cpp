#include <bits/stdc++.h>
using namespace std;
int mod_sum(int a, int b, int m)
{
    return (((a % m) + (b % m)) % m);
}
int mod_sub(int a, int b, int m)
{
    int p = ((a % m) - (b % m)) % m;
    p = (p >= 0) ? p : m + p;
    return p;
}
int mod_mult(int a, int b, int m)
{
    return (((a % m) * (b % m)) % m);
    /*
    for multiple modulo multiplication
    int l = v[0];
    for (int i = 1; i < n; i++)
    {
        l = mod_mult(l, v[i]);
    }
     */
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}