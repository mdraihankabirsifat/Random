#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        int rem = 0;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            if ((a + b) % 2 != rem)
            {
                m--;
                rem = (a + b) % 2;
            }
        }
        cout << m << endl;
    }
    return 0;
}