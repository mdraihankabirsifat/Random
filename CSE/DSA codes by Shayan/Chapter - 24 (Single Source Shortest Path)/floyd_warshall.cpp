#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int32_t main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        dis[u][v] = w;
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)  continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][i]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << dis[i][j] << ' ';
        cout << endl;
    }
    return 0;
}