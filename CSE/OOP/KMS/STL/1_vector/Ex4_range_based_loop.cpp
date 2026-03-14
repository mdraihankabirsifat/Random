#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> v(10);

    int i = 0;

    // initialize vector
    for (auto p = v.begin(); p != v.end(); ++p)
    {
        *p = i + 'a';
        i++;
    }

    cout << "Original contents:\n";

    // range based loop
    for (auto p : v)
        cout << p << " ";

    cout << "\n\n";

    return 0;
}

/*
Key Notes:

1. Range-based loop simplifies iteration.
2. Syntax:
      for(auto element : container)
3. Automatically visits each element.
4. Introduced in C++11.
*/