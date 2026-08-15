/*
Problem: Elevator Requests I

Starting from floor zero, process floor requests in their given order
and return the total time when moving one floor per second.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int elevatorRequests(int n, vector<int> &requests)
    {
        int x = requests.size();
        vector<int> v(x + 1);
        for (int i = 1; i <= x; i++)
        {
            v[i] = requests[i - 1];
        }
        int p = 0;
        for (int i = 1; i <= x; i++)
        {
            p += abs(v[i] - v[i - 1]);
        }
        return p;
    }
};
int main()
{
    int n = 5;
    vector<int> v = {2,0,0};
    Solution sol;
    cout << sol.elevatorRequests(n, v);
    return 0;
}
