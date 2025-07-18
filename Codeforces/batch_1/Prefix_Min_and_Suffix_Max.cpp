#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> initial(n), final(n);
        initial[0] = v[0];
        final[n - 1] = v[n - 1];
        for (int i = 1; i < n; i++)
        {
            initial[i] = min(initial[i - 1], v[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            final[i] = max(final[i + 1], v[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
            {
                cout << 1;
            }
            else
            {
                if (initial[i - 1] < v[i] && v[i] < final[i + 1])
                {
                    cout << 0;
                }
                else
                {
                    cout << 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}