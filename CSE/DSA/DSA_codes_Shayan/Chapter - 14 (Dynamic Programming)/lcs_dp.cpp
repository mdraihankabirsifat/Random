#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[0][0] << '\n';
    return 0;
}