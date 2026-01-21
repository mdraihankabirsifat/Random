#include <bits/stdc++.h>
using namespace std;
int main()
{
    // last input first output
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    cout << "top: " << q.front() << endl;

    queue<int> q2;
    q2.swap(q);
    cout << "s size: " << q.size() << endl;   // 0
    cout << "s2 size: " << q2.size() << endl; // 3

    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop(); // pop from the first
    }
    return 0;
}