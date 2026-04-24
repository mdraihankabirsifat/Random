#include<bits/stdc++.h>
using namespace std;
#define int long long

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
    int last = 1;
    for(int i = 2; i <= n; i++){
        if(a[i].first >= a[last].second){
            last = i;
            res.push_back(last);
        }
    }
    cout << (int)res.size() << '\n';
    for(auto ele : res) cout << a[ele].first << ' ' << a[ele].second << '\n';
    return 0;
}


// ACTIVITY_SELECTION(s, f, n):
// 1. Sort 'a' according to the non descending order of finish times
// 2. Make a set S = {a[1]}
// 3. last <- 1
// 4. for i = 2 to n
// 5.    if a[i].s >= last.f
// 6.       S = S U {a[i]}
// 7.       last = i
// 8. print S