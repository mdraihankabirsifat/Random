// https://codeforces.com/problemset/problem/1411/B
/*
Problem: Fair Numbers

Find the smallest integer at least n that is divisible by each of its
nonzero decimal digits.
*/

#include <bits/stdc++.h>
using namespace std;
bool digit(long long int n)
{
    long long int temp = n;
    while (temp > 0)
    {
        int r = (temp % 10);
        if (r != 0 && n % r)
        {
            return false;
        }
        temp = temp / 10;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        for (int i = 0; i < 2521; i++)
        {
            if (digit(n + i))
            {
                cout << (n + i) << endl;
                break;
            }
        }
    }
}
