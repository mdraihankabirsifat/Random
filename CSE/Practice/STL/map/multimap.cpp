#include <bits/stdc++.h>
using namespace std;
int main()
{
    //store repeated data, sorted
    multimap<string, int> m;
    m.insert({"tv", 100});
    m.insert({"tv", 50});
    m.insert({"tv", 30});
    m.insert({"tv", 10});
    m.emplace("Laptop",120);
    // will print 4 times
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    cout << "After removing one element: " << endl;
    m.erase(m.find("tv"));
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    cout << "After removing all similar element: " << endl;
    m.erase("tv");
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}