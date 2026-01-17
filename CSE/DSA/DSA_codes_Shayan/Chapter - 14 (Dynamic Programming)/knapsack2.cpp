#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int32_t main(){
    int n, w; cin >> n >> w;
    vector<pair<int, int>>a(n); int val = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        val += a[i].second;
    }
    vector<vector<int>>dp(n + 1, vector<int>(val + 1, INF));
    // dp[i][j] = min weight for total val = j from i to n - 1;
    // ans = dp[0][0];
    // {i, j} -> min((i + 1, j), (i + 1, j - a[i].val) + a[i].wgt);
    dp[n][0] = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= 0; j++){
            dp[i][j] = dp[i + 1][j];
            if(j - a[i].second >= 0)  
            dp[i][j] = min(dp[i][j], dp[i + 1][j - a[i].second] + a[i].first);
        }
    }
    int ans;
    for(int j = val; j >= 0; j--){
        if(dp[0][j] <= w){
            ans = j;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}