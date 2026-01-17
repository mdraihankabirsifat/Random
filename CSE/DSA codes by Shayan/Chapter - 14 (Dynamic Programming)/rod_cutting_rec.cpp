#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>&dp, vector<int>&a, vector<int>&part){
    if(n == 0)  return dp[n] = 0;
    if(dp[n] != -1) return dp[n];
    int ans;
    for(int i = 1; i <= n; i++){
        ans = a[i] + f(n - i, dp,a, part);
        if(ans > dp[n]){
            dp[n] = ans;
            part[n] = i;
        }
    }
    return dp[n];
}

int main(){
    int n; cin >> n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>dp(n + 1, -1), part(n + 1, -1);
    cout << f(n, dp, a, part) << '\n';
    int len = n;
    while(len > 0){
        cout << part[len] << ' ';
        len -= part[len];
    }
    cout << endl;
    return 0;
}