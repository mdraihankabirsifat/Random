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
        long long n;
        cin >> n;
        vector<long long> v(n), v1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i = i + 2)
        {
            v1[i] = (abs(v[i] - v[i - 1]));
        }
        cout << *max_element(v1.begin(), v1.end()) << "\n";
    }
    return 0;
}