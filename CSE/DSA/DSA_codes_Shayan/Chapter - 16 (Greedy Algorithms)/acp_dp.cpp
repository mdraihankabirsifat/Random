#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int32_t main(){
    int n; cin >> n;
    vector<pair<int, int>> a(n + 2);
    a[0] = {-INF, -INF};
    a[n + 1] = {INF, INF};
    // For safe bounds;
    for(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        a[i] = {r, l};
    }
    sort(a.begin() + 1, a.end() - 1);
    for(int i = 1; i <= n; i++) swap(a[i].first, a[i].second);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    // dp[i][j] = Max number of mutually compatible activities that are done after ith and before jth;
    // so for j = 0 to i + 1; dp[i][j] = 0;
    // ans = dp[0][n + 1]; Imagine the flow;
    for(int i = n + 1; i >= 0; i--){
        for(int j = i + 2; j <= n + 1; j++){
            for(int k = i + 1; k < j; k++){
                if(a[k].first > a[i].first && a[k].second < a[j].second){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + 1);
                }
            }
        }
    }
    cout << dp[0][n + 1] << '\n';
    return 0;
}

// Notes : 'a' stores all the activities. 'a' is sorted in non decreasing order of the finish time of the activities.
// ACTIVITY_SELECTION_IDP(s, f, n):
// 1. let c[0 :: n + 1] and act[0 :: n + 1] be two tables.
// 2. Fill table c[0 :: n + 1] with 0 and table act[0 :: n + 1] with -1.
// 3. for i = n + 1 to 0
// 4.    for j = i + 2 to n + 1
// 5.        for k = i + 1 to j - 1
// 6.            if(a[k].s > a[i].f && a[k].f < a[j].s)
// 7.                  ans <- c[i, k] + c[k, j] + 1
// 8.                      if(ans > c[i, j])
// 9.                         c[i, j] = ans
// 10.                       act[i, j] = k;
// 11. print "A maximum size of mutually compatible activities :" c[0 :: n + 1]
// 12. PRINT_ACTIVITIES(0, n + 1, act)

// PRINT_ACTIVITIES(i, j, act): 
//    1. k <- act[i, j]
//    2. if k = -1   return;
//    3. PRINT_ACTIVITIES(i, k, act)
//    4. print a[k].s and a[k].f
//    5. PRINT_ACTIVITIES(k, j, act)
