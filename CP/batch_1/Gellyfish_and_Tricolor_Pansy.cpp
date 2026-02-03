#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        a = min(a, c);
        b = min(b, d);
        if (a >= b)
        {
            cout << "Gellyfish" << endl;
        }
        else
        {
            cout << "Flower" << endl;
        }
    }
    return 0;
}
