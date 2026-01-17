#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, w;

int f(int i, int wgt, vector<pair<int, int>>&a, vector<vector<int>>&dp){
    if(i > n)   return dp[i][wgt] = 0;
    if(dp[i][wgt] != -1)    return dp[i][wgt];
    dp[i][wgt] = f(i + 1, wgt, a, dp);
    if(wgt - a[i].first >= 0)   
    dp[i][wgt] = max(dp[i][wgt], f(i + 1, wgt - a[i].first, a, dp) + a[i].second);
    return dp[i][wgt];
}


int32_t main(){
    cin >> n >> w;
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    vector<vector<int>>dp(n + 2, vector<int>(w + 2, -1));
    cout << f(1, w, a, dp) << '\n';
    return 0;
}