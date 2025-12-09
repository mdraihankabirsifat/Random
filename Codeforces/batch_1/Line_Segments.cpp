#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p1, p2, q1, q2;
        long long s = 0;
        cin >> n;
        cin >> p1 >> p2 >> q1 >> q2;
        long long r = 1LL * (p1 - q1) * (p1 - q1) + 1LL * (p2 - q2) * (p2 - q2);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s = s + v[i];
        }
        int mx = *max_element(v.begin(), v.end());
        long long rem = s - mx;
        if (r > s * s)
        {
            cout << "No" << endl;
        }
        else if (mx <= rem)
        {
            cout << "Yes" << endl;
        }
        else if (r >= (mx - rem) * (mx - rem))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}