#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, c = 1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i > 0)
        {
            if (v[i] != v[i - 1])
            {
                c++;
            }
        }
    }
    cout << c;
    return 0;
}