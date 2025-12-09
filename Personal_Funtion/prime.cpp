#include <bits/stdc++.h>
using namespace std;
vector<int> v;
// *************** prime number ***************//
void prime(int n)
{
    v.assign(n, 1);
    v[1] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i] == 1)
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                v[j] = 0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime(10);
    
    return 0;
}