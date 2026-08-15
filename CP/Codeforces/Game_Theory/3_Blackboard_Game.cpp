// https://codeforces.com/problemset/problem/2123/A
/*
Problem: Blackboard Game

For the given blackboard size, determine which player wins the number game
when both follow an optimal strategy.
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
        if (n % 4 == 0)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
        }
    }
    return 0;
}
