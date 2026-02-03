#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<bool> v(n + 1, true);
    int pos = 1;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        while (c < 2)
        {
            if (v[pos])
                c++;
            if (c < 2)
                pos = pos % n + 1;
        }
        cout << pos << " ";
        v[pos] = false;
        c = 0;
        pos = pos % n + 1;
        while (!v[pos] && i < n - 1)
            pos = pos % n + 1;
    }
    return 0;
}