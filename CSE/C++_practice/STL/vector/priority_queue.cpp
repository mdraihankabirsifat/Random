#include <bits/stdc++.h>
using namespace std;
int main()
{
    // push, emplace, pop, top, empty, size
    //  set elements in decreasinf order
    priority_queue<int> q;
    q.push(5);
    q.push(3);
    q.push(10);
    q.push(4);
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    // make it increasing
    priority_queue<int, vector<int>, greater<int>> q2;
    q2.push(5);
    q2.push(3);
    q2.push(10);
    q2.push(4);
    while (!q2.empty())
    {
        cout << q2.top() << " ";
        q2.pop();
    }
    return 0;
}