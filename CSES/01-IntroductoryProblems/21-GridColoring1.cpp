#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool used[4] = {};
            used[grid[i][j] - 'A'] = true;
            if (i > 0) used[grid[i - 1][j] - 'A'] = true;
            if (j > 0) used[grid[i][j - 1] - 'A'] = true;
            for (int k = 0; k < 4; ++k) {
                if (!used[k]) {
                    grid[i][j] = 'A' + k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << grid[i] << '\n';
    }
}
