#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, w; cin >> n >> w;
    vector<pair<int, int>>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    // {w, v};
    vector<vector<int>>dp(n + 2, vector<int>(w + 2));
    // Base case is already done since the 0th row is 0(not choosing anything)
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = w; j >= 0; j--){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j - a[i + 1].first >= 0)
            dp[i + 1][j - a[i + 1].first] =
             max(dp[i + 1][j - a[i + 1].first], dp[i][j] + a[i + 1].second);
        }
    }
    for(int j = 0; j <= w; j++) ans = max(ans, dp[n][j]);
    cout << ans << '\n';
    return 0;
}