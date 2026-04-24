#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

void print(int l, int r, vector<vector<int>>&choose){
    if(l == r){
        cout << 'A' << l;
        return;
    }
    int mid = choose[l][r];
    cout << "(";
    print(l, mid, choose);
    cout << " x ";
    print(mid + 1, r, choose); cout << ")";
}

int32_t main(){
    int n; cin >> n;
    vector<int>a(n+1);
    // ith matrix -> a[i - 1] * a[i] dimension
    for(int i = 0; i <= n; i++)     cin >> a[i];
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>>choose(n + 1, vector<int>(n + 1, -1));
    // dp[i][j] = Minimum number of scalar multiplications to calc from ith
    // to the jth matrix;
    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for(int i = n; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            for(int k = i; k < j; k++){
                int ans = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
                if(ans < dp[i][j]){
                    dp[i][j] = ans;
                    choose[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    print(1, n, choose); cout << endl;
    return 0;
}