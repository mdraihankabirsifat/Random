#include <bits/stdc++.h>
using namespace std;
int main()
{
    // practice on set taking multiple input then re-arrange it and print it
    // convert set to vector and then get the access of each element by indexing
    set<int> s;
    int n;
    cout << "How many elements? ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x); // insert into set
    }
    // set only keeps unique element
    cout << "Unique elements in sorted order:\n";
    for (int x : s)
    {
        cout << x << " ";
    }
    cout << "\n";
    vector<int> v(s.begin(), s.end()); // Now we can use indexing
    cout << v[2] << endl;
    return 0;
}