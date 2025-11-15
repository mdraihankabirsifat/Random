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
        long long n, a, i;
        cin >> n >> a;
        vector<long long> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 1 && a <= v[0])
        {
            cout << a + 1 << "\n";
            goto end;
        }
        else if(n == 1 && a > v[0])
        {
            cout << a - 1 << "\n";
            goto end;
        }
        for (i = 1; i < n; i++)
        {
            if (a <= v[0])
            {
                cout << a + 1 << "\n";
                break;
            }
            else if (a > v[i - 1] && a <= v[i] && (i + 1) <= (n / 2))
            {
                cout << a + 1 << "\n";
                break;
            }
            else if (a > v[i - 1] && a <= v[i] && (i + 1) > (n / 2))
            {
                cout << a - 1 << "\n";
                break;
            }
            else if (a > v[n - 1])
            {
                cout << a - 1 << "\n";
                break;
            }
        end:;
        }
    }
    return 0;
}