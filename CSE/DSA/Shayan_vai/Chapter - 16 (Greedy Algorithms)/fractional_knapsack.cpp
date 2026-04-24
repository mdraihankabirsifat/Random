#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, W; cin >> n >> W;
    vector<pair<double, double>> a(n + 1);
    vector<pair<double, int>> v(1, {0, 0});
    for(int i = 1; i <= n; i++){
        int val, wt; cin >> val >> wt;
        a[i] = {val, wt};
        v.push_back({val / wt, i});
    }
    sort(v.begin() + 1, v.end(), greater<pair<double, int>>());
    double ans = 0.0;
    for(int i = 1; i <= n; i++){
        int idx = v[i].second;
        if(a[idx].second <= W){
            ans += a[idx].first;
            W -= a[idx].second;
        }else{
            ans += W * v[i].first;
            W = 0;
            break;
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}