#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        __int128 n; // big integer
        long long c = 0;
        bool f = false;
        string s;
        cin >> s;
        n = 0;
        for (char ch : s)
        {
            n = n * 10 + (ch - '0'); // convert to __int128
        }
        __int128 temp = n;
        vector<__int128> v;
        __int128 p = 10; // 10^i
        while (temp != 0)
        {
            __int128 denom = 1 + p;
            if (n % denom == 0)
            {
                v.push_back(n / denom);
                c++;
                f = true;
            }
            temp /= 10;
            p *= 10; // next power of 10
        }
        reverse(v.begin(), v.end());
        if (!f)
        {
            cout << "0\n";
        }
        else
        {
            cout << c << "\n";
            for (__int128 x : v)
            {
                // print __int128 manually
                if (x == 0)
                {
                    cout << "0 ";
                    continue;
                }
                string out;
                while (x > 0)
                {
                    out.push_back('0' + (x % 10));
                    x /= 10;
                }
                reverse(out.begin(), out.end());
                cout << out << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}