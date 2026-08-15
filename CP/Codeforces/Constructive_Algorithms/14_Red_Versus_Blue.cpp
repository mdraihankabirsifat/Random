// https://codeforces.com/problemset/problem/1659/A
/*
Problem: Red Versus Blue

Arrange r red and b blue characters so blue characters are distributed
as evenly as possible among runs of red.
*/

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
        int n, r, b, p;
        cin >> n >> r >> b;
        p = b + 1;
        b++;
        for (int i = 0; i < p; i++)
        {
            int h = r / b;
            for (int j = 0; j < h; j++)
            {
                cout << "R";
            }
            if (b > 1)
            {
                cout << "B";
            }
            r = r - h;
            b--;
        }
        cout << "\n";
    }
    return 0;
}
