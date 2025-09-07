#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, s = 0;
    cin >> n >> q;
    vector<int> v(n), hol(n + 1), ger(n + 1), jer(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        hol[i + 1] = hol[i];
        ger[i + 1] = ger[i];
        jer[i + 1] = jer[i];
        if (v[i] == 1)
        {
            hol[i + 1]++;
        }
        else if (v[i] == 2)
        {
            ger[i + 1]++;
        }
        else
        {
            jer[i + 1]++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << hol[end] - hol[start - 1] << " "
             << ger[end] - ger[start - 1] << " "
             << jer[end] - jer[start - 1] << endl;
    }
    return 0;
}