#include<bits/stdc++.h>
using namespace std;
#define int long long
#define db long double


int32_t main(){
    int n; cin >> n; int one = 0, two = 0, three = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x == 1)  one++;
        else if(x == 2) two++;
        else three++;
    }
    vector<vector<vector<db>>>dp(n + 1, vector<vector<db>>(n + 1, vector<db>(n + 1)));
    // (i, j, k) -> state with i 1's, j 2's and k 3's
    // z = n - (i + j + k); number of zeroes
    // dp(i, j, k) -> 1 + (z / n) * dp(i, j, k) + (i / n) * dp(i - 1, j, k)
    // + (j / n) * f(i + 1, j - 1, k) + (k / n) * f(i, j + 1, k - 1);
    // (n - z) * dp(i,j,k) = n + i*dp(i-1,j,k) + j*dp(i+1,j-1,k) + k*dp(i,j+1,k-1)
    // dp(i,j,k) = (1 / (n-z)) *(n + ....)
    // deno = n - z = i+j+k;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                if(i + j + k == 0 || i + j + k > n) continue;
                int deno = i + j + k;
                db ans = n;
                if(i >= 1)   ans += i * dp[i - 1][j][k];
                if(j >= 1)  ans += j * dp[i + 1][j - 1][k];
                if(k >=1)  ans += k * dp[i][j + 1][k - 1];
                dp[i][j][k] = ans / deno;  
            }
        }
    } 
    cout << fixed << setprecision(10) << dp[one][two][three] << '\n';
    return 0;
}