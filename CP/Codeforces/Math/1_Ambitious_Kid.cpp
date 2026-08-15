// https://codeforces.com/problemset/problem/1866/A
/*
Problem: Ambitious Kid

Find the minimum absolute value among all elements of the array.
This is the least distance of any element from zero.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp = 1000000;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] < 0)
        {
            v[i] = -1 * v[i];
        }
        if (temp > v[i])
        {
            temp = v[i];
        }
    }
    cout << temp;
    return 0;
}
