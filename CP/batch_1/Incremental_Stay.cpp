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
        long long n, str = 0, end = 1, temp, sum = 0;
        cin >> n;
        temp = n;
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            str = 1;
            temp = i + 1;
            end = i + 2;
            for (int j = 0; j < n; j++)
            {
                sum = sum + v[end - 1] - v[str - 1];
                if (temp < n)
                {
                    end = end + 2;
                    temp++;
                }
                else
                {
                    end++;
                }
                if (str >= i + 1)
                {
                    str = str + 2;
                }
                else
                {
                    str++;
                }
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}