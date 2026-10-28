#include <iostream>
#include <vector>
#include <queue>

const int INF = 1e9;
const int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> moves(n, std::vector<int>(n, INF));
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    moves[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X >= 0 && Y >= 0 && X < n && Y < n) {
                if (moves[X][Y] > moves[x][y] + 1) {
                    moves[X][Y] = moves[x][y] + 1;
                    q.emplace(X, Y);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << moves[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }
}
