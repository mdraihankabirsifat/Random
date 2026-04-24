#include<bits/stdc++.h>
using namespace std;

string build(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
    if(i == 0 || j == 0)  return "";
    if(s1[i] == s2[j])  return build(i - 1, j - 1, s1, s2, dp) + s1[i];
    else{
        if(dp[i - 1][j] > dp[i][j - 1]) return build(i - 1, j, s1, s2, dp);
        else return build(i, j - 1, s1, s2, dp);
    }
}

int main(){
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = "1" + s1, s2 = "1" + s2;
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    // ans = dp[n][m]; // Base case already done as the 0th row and col are done;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i] == s2[j])  dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m] << '\n';
    string ans = build(n, m, s1, s2, dp);
    cout << ans << '\n';
    return 0;
}