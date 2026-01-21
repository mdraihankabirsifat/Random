#include <bits/stdc++.h>
using namespace std;
int main()
{
    //first in first out
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << "\n";
    q.pop();
    cout << q.front() << "\n";
    if (q.empty())
    {
        cout << "null\n";
    }
    else
    {
        cout << "something in it\n";
    }
    return 0;
}