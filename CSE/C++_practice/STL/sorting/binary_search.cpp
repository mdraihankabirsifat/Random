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
    sort(v.begin(), v.end()); // safer to sort then binary search
    cout << binary_search(v.begin(), v.end(),2) << endl; //if 2 xists in the vector, print 1, else print 0
    return 0;
}