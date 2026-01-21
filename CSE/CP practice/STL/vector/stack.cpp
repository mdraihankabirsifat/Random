#include <bits/stdc++.h>
using namespace std;
int main()
{
    // last input first output
    stack<int> s;
    s.push(1);
    s.push(2);
    s.emplace(3);
    cout << "top: " << s.top() << endl;

    stack<int> s2;
    s2.swap(s);
    cout << "s size: " << s.size() << endl;   // 0
    cout << "s2 size: " << s2.size() << endl; // 3

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop(); // pop from the last
    }
    return 0;
}