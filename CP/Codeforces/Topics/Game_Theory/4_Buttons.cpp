// https://codeforces.com/problemset/problem/1858/A
/*
Problem: Buttons

Alice, Bob, and a neutral pile of buttons take turns choosing available buttons.
Determine the winner from the three pile sizes under optimal play.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c % 2 != 0 && a >= b)
        {
            cout << "First" << endl;
        }
        else if (c % 2 != 0 && a < b)
        {
            cout << "Second" << endl;
        }
        else if (c % 2 == 0 && a <= b)
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
