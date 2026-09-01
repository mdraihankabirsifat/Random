#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

struct State
{
    int r, c;
    int mask;
    int en;
    int dist;
};

class Solution
{
public:
    int minMoves(vector<string> &v, int energy)
    {
        int m = v.size(), n = v[0].size(), sr = -1, sc = -1, cnt = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 'S')
                {
                    sr = i;
                    sc = j;
                }
                if (v[i][j] == 'L')
                {
                    id[i][j] = cnt++;
                }
            }
        }
        int mask = 1 << cnt;
        int fm = mask - 1;
        vector<vector<vector<int>>> best;
        best.resize(m, vector<vector<int>>(n, vector<int>(mask, -1)));
        queue<State> q;
        q.push({sr, sc, 0, energy, 0});
        best[sr][sc][0] = energy;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty())
        {
            State cur = q.front();
            q.pop();
            int r = cur.r, c = cur.c, mask = cur.mask, en = cur.en, dist = cur.dist;
            if (mask == fm)
            {
                return dist;
            }
            if (en == 0)
            {
                continue;
            }
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                {
                    continue;
                }
                if (v[nr][nc] == 'X')
                {
                    continue;
                }
                int ne = en - 1, nm = mask;
                if (v[nr][nc] == 'L')
                {
                    nm |= (1 << id[nr][nc]);
                }
                if (v[nr][nc] == 'R')
                {
                    ne = energy;
                }
                if (best[nr][nc][nm] >= ne)
                {
                    continue;
                }
                best[nr][nc][nm] = ne;
                q.push({nr, nc, nm, ne, dist + 1});
            }
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v = {};
    string s = "";
    int n;
    Solution sol;
    cout << sol.minMoves(v, n);
    return 0;
}