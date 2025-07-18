#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    int sz = v.size();
    cout << sz << "\n";
    for (int i = 0; i < sz; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}