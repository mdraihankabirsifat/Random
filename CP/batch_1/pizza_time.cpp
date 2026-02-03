#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, c = 0;
        cin >> n;
        while (n > 3)
        {
            c = c + n / 3;
            n = (n / 3) + (n % 3);
        }
        if (n == 3)
        {
            c++;
        }
        cout << c << "\n";
    }
    return 0;
}