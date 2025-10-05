#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dq[i];
    }
    // dq.push_back(2);
    // dq.push_back(3);
    // dq.pop_back();
    dq.pop_front();
    int sz = dq.size();
    for (int i = 0; i < sz; i++)
    {
        cout << dq[i] << " ";
    }
    cout << "\n";
    return 0;
}