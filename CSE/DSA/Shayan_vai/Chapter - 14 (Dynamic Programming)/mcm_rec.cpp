#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int f(int i, int j, vector<int>&a, vector<vector<int>>&dp, vector<vector<int>>&choose){
        if(i == j)  return dp[i][j] = 0;
        if(dp[i][j] != INF) return dp[i][j];
        int ans;
        for(int k = i; k < j; k++){
            ans = f(i, k, a, dp, choose) + f(k + 1, j, a, dp, choose)
            + a[i - 1] * a[k] * a[j];
            if(ans < dp[i][j]){
                dp[i][j] = ans;
                choose[i][j] = k;
            }
        }
        return dp[i][j];
}

void print(int l, int r, vector<vector<int>>&choose){
    if(l == r){
        cout << "A" << l; return;
    }
    int mid = choose[l][r];
    cout << "(";
    print(l, mid, choose);
    cout << " x ";
    print(mid + 1, r, choose); cout << ")";
}

int32_t main(){
    int n; cin >> n;
    vector<int>a(n + 1);
    for(int i = 0; i <= n; i++) cin >> a[i];
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>>choose(n + 1, vector<int>(n + 1, -1));
    cout << f(1, n, a, dp, choose) << '\n';
    print(1, n, choose);
    cout << endl;
    return 0;
}