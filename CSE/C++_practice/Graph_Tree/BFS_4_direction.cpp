#include <vector>
#include <queue>
#include <string>
using namespace std;

// BFS on 2D grid with 4-directional movement
// (sx, sy): starting position, grid: 2D grid, n: rows, m: columns
// '#' represents blocked cells
// Returns: dist[i][j] = shortest distance from start to (i,j), or -1 if unreachable
vector<vector<int>> BFS_Grid(
    int sx, int sy,
    vector<string> &grid,
    int n, int m)
{
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    dist[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // boundaries + not visited + free cell
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                dist[nx][ny] == -1 &&
                grid[nx][ny] != '#')
            {

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist;
}
