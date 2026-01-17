#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int>a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>dp(n + 1), part(n + 1, -1);
    for(int i = 1; i <= n; i++) dp[i] = a[i];
    for(int len = 1; len <= n; len++){
        for(int i = 1; i <= len; i++){
            int ans = dp[len - i] + a[i];
            if(ans > dp[len]){
                dp[len] = ans;
                part[len] = i;
            }
        }
    }
    cout << dp[n] << '\n';
    int len = n;
    while(len > 0){
        cout << part[len] << ' ';
        len -= part[len];
    }
    cout << endl;
    return 0;
}