#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    int m = *max_element(v.begin(), v.end());
    cout << m << endl;
    return 0;
}