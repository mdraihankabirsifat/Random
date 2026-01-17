#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    // dp[i][j] = length of LCS upto ith index of s1 and jth index of s2;
    // ans = dp[n - 1][m - 1];
    // Think about the base case;
    // for(int j = 0; j < m; j++){
    //     if(s1[0] == s2[j])  dp[0][j] = 1;
    // }
    // for(int i = 0; i < n; i++){            // This initialization has a bug
    //     if(s2[0] == s1[i])  dp[i][0] = 1;   // it doesn't count the res of prev
    // }                                       // indices
    // First row and the first column is filled as the base case.
    // So start from the second row;
    // Fix the traversal path;
    if(s1[0] == s2[0])  dp[0][0] = 1;
    for(int j = 1; j < m; j++){
        if(dp[0][j - 1] || s1[0] == s2[j]){
            dp[0][j] = 1; 
        }
    }
    for(int i = 1; i < n; i++){
        if(dp[i - 1][0] || s1[i] == s2[0]){
            dp[i][0] = 1;
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}


// Thumb rule for smooth dp transition : 
// upto idx dp : consider an extra row and column and solve in 1 based
// coz we have to extract element from behind in this case. So, it's better
// to consider 0th row or 0th col as the base case;

// pointer dp : Add an extra row and column and use them as the base case;
// u can use 1 based indexing if u need but not that necessary;