#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db long double

int32_t main(){
    int n; cin >> n; vector<db>p(n + 1);
    for(int i = 1; i <= n; i++)  cin >> p[i];
    vector<vector<db>>dp(n + 1, vector<db>(n + 1));
    // dp[i][j] = probability of j heads upto ith index;
    // base case is : 0th row;
    // (i, j) -> (i - 1, j - 1) * p[i] + (i - 1, j) * (1-p[i]);
    // ans = sum of dp[n][k] for k = [n / 2 + 1, n];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = dp[i - 1][j] * (1 - p[i]);
            if(j > 0)   dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    }
    db ans = 0;
    for(int j = n / 2 + 1; j <= n; j++) ans += dp[n][j];
    cout << ans << '\n';
    return 0;
}