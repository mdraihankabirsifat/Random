#include <bits/stdc++.h>
using namespace std;
int main()
{
    // follows lexicographical ascending order (sorted)
    // if you put same key repeatedly map will store it for once
    map<string, int> m;
    m["Tv"] = 100;
    m["Tv"] = 100;
    m["Laptop"] = 50;
    m["Tablet"] = 30;
    m["Watch"] = 120;
    m["watch"] = 20;
    m.insert({"Camera", 80});
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    cout << "Count: " << m.count("Laptop") << endl;       // Number of times it appears not the key value
    cout << "Number of Laptops: " << m["Laptop"] << endl; // key value
    if (m.find("Camera") != m.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    } 
    return 0;
}