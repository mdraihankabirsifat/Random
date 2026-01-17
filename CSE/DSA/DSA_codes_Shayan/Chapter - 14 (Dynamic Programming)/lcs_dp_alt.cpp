#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    // dp[i][j] = length of lcs upto ith index of s1 and jth index of s2;
    // ans = dp[n - 1][m - 1];
    // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) || 1 + dp[i - 1][j - 1];
    // Fill the first row as the base case;
    // No need because 0th row and 0th col are already filled with zeroes
    // indicating the base case;
    // Make 1 based indexing for easily handling the base case;
    // ans = dp[n][m]. Fix the traversal path;
    s1 = "1" + s1;
    s2 = "1" + s2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}