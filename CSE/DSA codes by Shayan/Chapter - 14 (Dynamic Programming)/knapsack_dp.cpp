// Knapsack is a take or not take i.e. a subsequence DP.
// So we will just calculate the answer upto an index in the base case
// and extend it to the later indices or we may also apply pointer DP
// Always take the state before the operation. It will make things sinpler

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, w; cin >> n >> w;
    vector<pair<int, int>>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    vector<vector<int>>dp(n + 1, vector<int>(w + 1));
    // dp[i][j] = max val taken upto i if the weight before choosing / not choosing 
    // is j;
    // dp[i][j] = max(dp[i - 1][j - a[i].wt] + a[i].val,dp[i - 1][j]);
    // max(dp[n][j]); // 0th row already gives us the base case!
    int ans = dp[0][0];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - a[i].first >= 0)    
            dp[i][j] = max(dp[i][j], a[i].second + dp[i - 1][j - a[i].first]);
            if(i == n)  ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}


