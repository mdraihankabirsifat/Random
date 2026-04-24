// LIS (Longest common subsequence) is a comparison type dp
// beacuse the addition of a new element requires the new element to be
// compared with last element of the last LIS

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n; cin >> n;
    vector<int>a(n + 1); for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int>dp(n+1, 1);
    // dp[i] = length of LIS that ends at ith index; // Useful for comparison dp
    // There are two options for a sequence to end at i;
    // Just having i or concatening it with some previous j;
    int ans = dp[1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[i] >= a[j])    dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}