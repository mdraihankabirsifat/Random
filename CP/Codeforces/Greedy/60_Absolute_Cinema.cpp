// https://codeforces.com/problemset/problem/2229/B
/*
Problem: Absolute Cinema

For paired cinema values, choose the orientation of each pair to
maximize the required total score.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tata "\n"
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> v1(n), v2(n);
        in(v1);
        in(v2);
        for (int i = 0; i < n; i++)
        {
            if (v1[i] > v2[i])
            {
                swap(v1[i], v2[i]);
            }
        }
        cout << jog(v2) + boro(v1) << tata;
    }
    return 0;
}
