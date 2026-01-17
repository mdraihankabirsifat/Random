#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, w; cin >> n >> w;
    vector<pair<int, int>>a(n);
    for(int i = 0; i < n; i++)  cin >> a[i].first >> a[i].second;
    vector<vector<int>>dp(n + 1, vector<int>(w + 1));
    // Base case is the nth row -> Already initialized
    // ans = dp[0][w];
    // (i, j) -> max((i + 1, j), (i + 1, j - a[i].wt) + a[i].val))
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i + 1][j];
            if(j - a[i].first >= 0)
            dp[i][j] = max(dp[i][j], dp[i + 1][j - a[i].first] + a[i].second);
        }
    }
    cout << dp[0][w] << '\n';
    return 0;
}