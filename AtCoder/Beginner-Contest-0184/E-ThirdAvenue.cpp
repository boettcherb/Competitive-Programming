#include <iostream>
#include <vector>
#include <queue>
#include <map>

const int INF = 2e9;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> grid(n);
    std::map<char, std::vector<std::pair<int, int>>> teleport;
    std::pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'S') start = { i, j };
            if (grid[i][j] == 'G') end = { i, j };
            if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                teleport[grid[i][j]].emplace_back(i, j);
            }
        }
    }
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, INF));
    dist[start.first][start.second] = 0;
    std::queue<std::pair<int, int>> q;
    q.emplace(start.first, start.second);
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X >= 0 && Y >= 0 && X < n && Y < m) {
                if (grid[X][Y] != '#' && dist[X][Y] > dist[x][y] + 1) {
                    dist[X][Y] = dist[x][y] + 1;
                    q.emplace(X, Y);
                }
            }
        }
        if (grid[x][y] >= 'a' && grid[x][y] <= 'z') {
            for (const auto [tx, ty] : teleport[grid[x][y]]) {
                if (dist[tx][ty] > dist[x][y] + 1) {
                    dist[tx][ty] = dist[x][y] + 1;
                    q.emplace(tx, ty);
                }
            }
            teleport[grid[x][y]].clear();
        }
    }
    int res = dist[end.first][end.second];
    std::cout << (res == INF ? -1 : res) << '\n';
}
