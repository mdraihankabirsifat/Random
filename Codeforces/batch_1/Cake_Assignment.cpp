#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool check(long long a, long long b, long long x)
{
    if (a == x)
    {
        return true;
    }
    if (a <= 0 || b <= 0)
    {
        return false;
    }
    if (a % 2 == 1 && b % 2 == 1 && a != x)
    {
        return false;
    }
    if (a % 2 == 0)
    {
        v.push_back(1);
        if (check(a / 2, b + a / 2, x))
        {
            return true;
        }
        v.pop_back();
    }
    if (b % 2 == 0)
    {
        v.push_back(2);
        if (check(a + b / 2, b / 2, x))
        {
            return true;
        }
        v.pop_back();
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k, x;
        cin >> k >> x;
        v.clear();
        long long a = pow(2, k);
        check(a, a, x);
        cout << v.size() << "\n";
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}