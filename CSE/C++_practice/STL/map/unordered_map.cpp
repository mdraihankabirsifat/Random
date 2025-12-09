#include <bits/stdc++.h>
using namespace std;
int main()
{
    // stored data randomly, no repeatation
    unordered_map<string, int> m;
    m["Tv"] = 100;
    m["Tv"] = 100;
    m["Laptop"] = 50;
    m["Tablet"] = 30;
    m["Watch"] = 120;
    m["watch"] = 20;
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}