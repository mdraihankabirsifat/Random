#include<bits/stdc++.h>
using namespace std;
#define int long long

void f(int i, int n, vector<int>& res, vector<pair<int, int>>& a){
    if(i > n)   return;
    if(a[i].first >= a[res.back()].second){
        res.push_back(i);
    }
    f(i + 1, n, res, a);
}

int32_t main(){
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        a[i] = {r, l};
    }
    sort(a.begin() + 1, a.end());
    for(int i = 1; i <= n; i++) swap(a[i].first, a[i].second);
    vector<int> res(1, 1);
    f(2, n, res, a);
    cout << (int)res.size() << '\n';
    for(auto ele : res) cout << a[ele].first << ' ' << a[ele].second << '\n';
    return 0;
}


// ACTIVITY_SELECTION(i, s, f, n):
// 1. Make a set S
// 2. last = NULL
// 3. if i == 1 
//      4. S = S U {a[i]}
//      5. last = i 
// 4. if i > n return
// 5. if i.s >= last.f  S = S U {a[i]}
// 6. ACTIVITY_SELECTION(i + 1, s, f, n)