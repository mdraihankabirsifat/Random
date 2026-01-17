#include<bits/stdc++.h>
using namespace std;

// Pass the strings by reference or else TLE!

int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    int n = s1.size(), m = s2.size();
    if(i >= n || j >= m)    return dp[i][j] = 0;
    if(dp[i][j] != -1)  return dp[i][j];
    dp[i][j] = 0;
    if(s1[i] != s2[j])  dp[i][j] = max(f(i + 1, j, s1, s2, dp), f(i, j + 1, s1, s2, dp));
    else dp[i][j] = 1 + f(i + 1, j + 1, s1,s2, dp);
    return dp[i][j];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;int n = s1.size(), m = s2.size();
    vector<vector<int>>dp(n + 2, vector<int>(m + 2, -1));
    cout << f(0, 0, s1, s2, dp) << '\n';
    return 0;
}