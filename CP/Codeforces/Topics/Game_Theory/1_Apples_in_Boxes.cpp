// https://codeforces.com/problemset/problem/2107/B
/*
Problem: Apples in Boxes

Players remove one apple per turn without making max(a)-min(a) exceed k.
Determine the winner when Tom moves first and both play optimally.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, max, min, c = 0;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        sort(v.begin(), v.end());
        v[n - 1]--;
        sort(v.begin(), v.end());
        if (v[n - 1] - v[0] > k || sum % 2 == 0)
        {
            cout << "Jerry\n";
            continue;
        }
        cout << "Tom\n";
    }
    return 0;
}
