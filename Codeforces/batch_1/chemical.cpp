#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        set<int> s;
        vector<int> vns(n);
        for (int i = 0; i < n; i++) {
            cin >> vns[i];
        }
        vector<vector<int>> vms;
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            vms.push_back({x, y, z});
            s.insert(x);
            s.insert(y);
            s.insert(z);
        }
        cout << s.size() << endl;
        
    }
    return 0;
}