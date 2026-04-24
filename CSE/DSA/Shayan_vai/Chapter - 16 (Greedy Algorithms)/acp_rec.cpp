#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int f(int i, int j, vector<pair<int, int>>& a, vector<vector<int>>& dp, int n){
    if(j <= i + 1)  return dp[i][j] = 0;
    if(dp[i][j] != -1)   return dp[i][j];
    dp[i][j] = 0;
    for(int k = i + 1; k < j; k++){
        if(a[k].first > a[i].first && a[k].second < a[j].second){
            dp[i][j] = max(dp[i][j], f(i, k, a, dp, n) + f(k, j, a, dp, n) + 1);
        }
    }
    return dp[i][j];
}

int32_t main(){
    int n; cin >> n;
    vector<pair<int, int>> a(n + 2);
    a[0] = {-INF, -INF};
    a[n + 1] = {INF, INF};
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        a[i] = {r, l};
    }
    sort(a.begin() + 1, a.end() - 1);
    for(int i = 1; i <= n; i++) swap(a[i].first, a[i].second);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1)); // For Memoization;
    // dp[i][j] = Maximum number of mutually compatible activities that start after ith and end before jth;
    cout << f(0, n + 1, a, dp, n) << '\n';
    return 0;
}



// ACTIVITY_SELECTION_RDP(s, f, n):
// 1. let c[0 :: n + 1] and act[0 :: n + 1] be two tables
// 2. fill both of the tables with -1
// 3. REC(0, n + 1, c, act, n)
// 4. PRINT_ACTIVITIES(0, n + 1, act)

// REC(i, j, c, act, n):
// 1. if j <= i + 1   return c[i, j] = 0
// 2. if c[i, j] != -1   return c[i, j]
// 3. c[i, j] <- 0
// 4. for k = i + 1 to j - 1
// 5.    if(a[k].s > a[i].f && a[k].f < a[j].s)
// 6.        ans <- f(i, k, c, act, n)
// 7.        if ans > c[i, j]
// 8.           c[i, j] = ans
// 9.           act[i, j] = k
// 10. return c[i, j]

// PRINT_ACTIVITIES(i, j, act):
// 1. k <- act[i, j]
// 2. if k == -1 return;
// 3. PRINT_ACTIVITIES(i, k, act)
// 4. print a[k].s and a[k].f
// 5. PRINT_ACTIVITIES(k, j, act)

