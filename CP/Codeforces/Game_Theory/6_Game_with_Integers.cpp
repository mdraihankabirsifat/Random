// https://codeforces.com/problemset/problem/1899/A
/*
Problem: Game with Integers

Players alternately add or subtract one from an integer.
Determine whether the first player can force the number to become divisible by three.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 3 == 0)
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
    }
    return 0;
}
