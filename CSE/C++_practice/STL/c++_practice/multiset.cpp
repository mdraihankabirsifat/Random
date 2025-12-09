#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(10);
    ms.insert(10);
    ms.insert(5);
    ms.insert(5);
    for (auto x : ms)
    {
        cout << x << " ";
    }
    cout << "\n";

    ms.erase(10); //erase all
    for (auto x : ms)
    {
        cout << x << " ";
    }
    cout << "\n";

    ms.erase(ms.find(5)); //find and erase 1st incident
    for (auto x : ms)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}